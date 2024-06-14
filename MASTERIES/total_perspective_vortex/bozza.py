######################################
#        Bozza GPT-4o                #
######################################

import mne
from mne.datasets import eegbci
from mne.io import concatenate_raws, read_raw_edf
from mne import Epochs, pick_types, events_from_annotations
import numpy as np
import matplotlib.pyplot as plt
from sklearn.pipeline import Pipeline
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis as LDA
from sklearn.model_selection import train_test_split



# Define the subject and runs
subject = 1
runs = [6, 10, 14]  # Motor imagery runs
# Load data
raw_fnames = eegbci.load_data(subject, runs)
raw = concatenate_raws([read_raw_edf(f, preload=True) for f in raw_fnames])
# Set the EEG montage
raw.set_montage('standard_1020', match_case=False, match_alias=True, on_missing='warn')
# Plot raw data
raw.plot(n_channels=10, scalings='auto')
# Filter the data
raw.filter(7., 30., fir_design='firwin', skip_by_annotation='edge')
# Plot filtered data
raw.plot(n_channels=10, scalings='auto')
# Get events
events, _ = events_from_annotations(raw)
# Define epochs
picks = pick_types(raw.info, meg=False, eeg=True, stim=False, eog=False)
epochs = Epochs(raw, events, event_id={'T1': 2, 'T2': 3}, tmin=0.0, tmax=4.0, picks=picks, baseline=None, preload=True)
epochs_train = epochs.copy().crop(tmin=0., tmax=2.)  # Training on first 2 seconds
# Get data and labels
X = epochs_train.get_data( copy=False)  # EEG data
y = epochs_train.events[:, -1]  # Labels

from mne.decoding import CSP

# Initialize CSP
csp = CSP(n_components=4, reg=None, log=True, cov_est='epoch')
# Create a pipeline with CSP and LDA
pipeline = Pipeline([
	('CSP', csp),
	('LDA', LDA())
])
from sklearn.model_selection import cross_val_score
# Evaluate the pipeline
scores = cross_val_score(pipeline, X, y, cv=5, scoring='accuracy')
print(f'Cross-validation accuracy: {np.mean(scores):.2f} ± {np.std(scores):.2f}')

# Custom CSP implementation

# from sklearn.base import BaseEstimator, TransformerMixin
# from scipy.linalg import eigh

# class CustomCSP(BaseEstimator, TransformerMixin):
#     def __init__(self, n_components=4):
#         self.n_components = n_components

#     def fit(self, X, y):
#         # Compute covariance matrices
#         covs = [np.cov(X[y == i].reshape(X[y == i].shape[0], -1), rowvar=False) for i in np.unique(y)]
#         # Solve the eigenvalue problem
#         _, eig_vecs = eigh(covs[0], covs[0] + covs[1])
#         # Select the top n_components eigenvectors
#         self.filters_ = eig_vecs[:, ::-1][:, :self.n_components].T
#         return self

#     def transform(self, X):
#         # Apply the spatial filters
#         return np.dot(X, self.filters_.T)

# # Replace the CSP in the pipeline with CustomCSP
# pipeline = Pipeline([
#     ('CSP', CustomCSP(n_components=4)),
#     ('LDA', LDA())
# ])

# # Evaluate the pipeline with custom CSP
# scores = cross_val_score(pipeline, X, y, cv=5, scoring='accuracy')
# print(f'Cross-validation accuracy with custom CSP: {np.mean(scores):.2f} ± {np.std(scores):.2f}')

# #Save the data
# np.save('X.npy', X)
# np.save('y.npy', y)


# # Load the test data
# X = np.load('X.npy')
# y = np.load('y.npy')

# Split the data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
# Fit the pipeline on the training data
pipeline.fit(X_train, y_train)
# Evaluate on the test data
test_score = pipeline.score(X_test, y_test)
print(f'Test accuracy: {test_score:.2f}')


import time
# Simulate a stream of data
def simulate_stream(pipeline, X_test, delay=2.0):
	print(X_test.shape)
	for i in range(len(X_test)):
		chunk = X_test[i].reshape(1, X_test.shape[1], X_test.shape[2])
		start_time = time.time()
		pred = pipeline.predict(chunk)
		end_time = time.time()
		print(f'Prediction: {pred[0]}, Processing time: {end_time - start_time:.2f}s')
		time.sleep(delay)

simulate_stream(pipeline, X_test)
