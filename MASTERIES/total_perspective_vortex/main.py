import sys
import numpy as np
import mne
from mne.datasets import eegbci
from mne.io import concatenate_raws, read_raw_edf
from mne import Epochs, pick_types, events_from_annotations
from sklearn.pipeline import Pipeline
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis as LDA
from sklearn.model_selection import cross_val_score, train_test_split
from sklearn.base import BaseEstimator, TransformerMixin
from scipy.linalg import eigh

class CustomCSP(BaseEstimator, TransformerMixin):
	def __init__(self, n_components=4):
		self.n_components = n_components

	def fit(self, X, y):
		covs = [np.cov(X[y == i].reshape(X[y == i].shape[0], -1), rowvar=False) for i in np.unique(y)]
		_, eig_vecs = eigh(covs[0], covs[0] + covs[1])
		self.filters_ = eig_vecs[:, ::-1][:, :self.n_components].T
		return self

	def transform(self, X):
		return np.dot(X, self.filters_.T)

def load_data(subject, runs):
	raw_fnames = eegbci.load_data(subject, runs)
	raw = concatenate_raws([read_raw_edf(f, preload=True) for f in raw_fnames])
	new_channel_names = {name: name.replace('.', '') for name in raw.info['ch_names']}
	raw.rename_channels(new_channel_names)
	raw.set_montage('standard_1020', match_case=False, match_alias=True, on_missing='ignore')
	raw.filter(7., 30., fir_design='firwin', skip_by_annotation='edge')
	events, _ = events_from_annotations(raw)
	picks = pick_types(raw.info, meg=False, eeg=True, stim=False, eog=False)
	epochs = Epochs(raw, events, event_id={'T1': 2, 'T2': 3}, tmin=0.0, tmax=4.0, picks=picks, baseline=None, preload=True)
	return epochs

def train(subject, runs):
	epochs = load_data(subject, runs)
	epochs_train = epochs.copy().crop(tmin=0., tmax=1.)  # Training on first 2 seconds
	X = epochs_train.get_data( copy=False)  # EEG data
	y = epochs_train.events[:, -1]  # Labels
	csp = CustomCSP(n_components=4)
	lda = LDA()
	pipeline = Pipeline([('CSP', csp), ('LDA', lda)])
	scores = cross_val_score(pipeline, X, y, cv=5, scoring='accuracy', error_score='raise')
	print(f'{scores.tolist()}')
	print(f'cross_val_score: {np.mean(scores):.4f}')

def predict(subject, runs):
	epochs = load_data(subject, runs)
	epochs_train = epochs.copy().crop(tmin=0., tmax=2.)  # Training on first 2 seconds
	X = epochs_train.get_data( copy=False)  # EEG data
	y = epochs_train.events[:, -1]  # Labels
	X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
	csp = CustomCSP(n_components=4)
	lda = LDA()
	pipeline = Pipeline([('CSP', csp), ('LDA', lda)])
	pipeline.fit(X_train, y_train)
	predictions = pipeline.predict(X_test)
	accuracy = np.mean(predictions == y_test)
	for i, (pred, true) in enumerate(zip(predictions, y_test)):
		print(f'epoch {i:02d}: [{pred}] [{true}] {pred == true}')
	print(f'Accuracy: {accuracy:.4f}')

def experiment():
	subjects = range(1, 110)
	accuracies = []
	for subject in subjects:
		epochs = load_data(subject, [6, 10, 14])
		epochs_test = epochs.copy().crop(tmin=0., tmax=1.)  # Training on first 2 seconds
		X = epochs_test.get_data( copy=False)  # EEG data
		y = epochs_test.events[:, -1]  # Labels
		csp = CustomCSP(n_components=4)
		lda = LDA()
		pipeline = Pipeline([('CSP', csp), ('LDA', lda)])
		scores = cross_val_score(pipeline, X, y, cv=5, scoring='accuracy')
		accuracy = np.mean(scores)
		accuracies.append(accuracy)
		print(f'experiment 0: subject {subject:03d}: accuracy = {accuracy:.4f}')
	mean_accuracies = np.mean(accuracies)
	print(f'Mean accuracy of 6 experiments: {mean_accuracies:.4f}')

def main():
	if len(sys.argv) == 4:
		mode = sys.argv[3]
		subject = int(sys.argv[1])
		runs = [int(run) for run in sys.argv[2].split(',')]
		if mode == 'train':
			train(subject, runs)
		elif mode == 'predict':
			predict(subject, runs)
		else:
			print("Invalid mode. Use 'train' or 'predict'.")
	elif len(sys.argv) == 1:
		experiment()
	else:
		print("Invalid arguments. Usage: python bci.py <subject> <runs> <mode>")

if __name__ == "__main__":
	main()
