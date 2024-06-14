import sys
import numpy as np
import mne
from mne.datasets import eegbci
from mne.io import concatenate_raws, read_raw_edf
from sklearn.pipeline import Pipeline
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis as LDA
from sklearn.model_selection import cross_val_score, train_test_split
from sklearn.base import BaseEstimator, TransformerMixin
from scipy.linalg import eigh
import matplotlib.pyplot as plt


# class CustomCSP(BaseEstimator, TransformerMixin):
# 	def __init__(self, n_components=4):
# 		self.n_components = n_components

# 	def fit(self, X, y):
# 		covs = [np.cov(X[y == i].reshape(X[y == i].shape[0], -1), rowvar=False) for i in np.unique(y)]
# 		_, eig_vecs = eigh(covs[0], covs[0] + covs[1])
# 		self.filters_ = eig_vecs[:, ::-1][:, :self.n_components].T
# 		return self

# 	def transform(self, X):
# 		return np.dot(X, self.filters_.T)

# Load and concatenate the EEGBCI data
subject = 1
runs = [6, 10, 14]
raw_files = eegbci.load_data(subject, runs)
raw = concatenate_raws([read_raw_edf(f, preload=True) for f in raw_files])

# Remove trailing dots from channel names
raw.rename_channels(lambda x: x.strip('.')) 

# Set the montage explicitly
montage = mne.channels.make_standard_montage('standard_1020')
raw.set_montage(montage, match_case=False, match_alias=True, on_missing='ignore')

# # Verify that the montage was applied correctly by plotting sensor positions
# fig = raw.plot_sensors(show_names=True)
# plt.show()

# Print raw info
print(raw)
print(raw.info)

# Compute and plot the Power Spectral Density (PSD)
# raw.compute_psd(fmax=50).plot(picks="data", exclude="bads", amplitude=False)

# Plot the raw data
raw.plot(duration=5, n_channels=30)


events = mne.find_events(raw, shortest_event=1, stim_channel='STI 014')

# picks = mne.pick_channels(raw.info["ch_names"], ["C3", "Cz", "C4"])
picks = mne.pick_types(raw.info, eeg=True, eog=True, stim=False, exclude='bads')

tmin, tmax = -1, 4  # define epochs around events (in s)
event_ids = dict(hands=2, feet=3)  # map event IDs to tasks

epochs = mne.Epochs(raw, events, event_ids, tmin - 0.5, tmax + 0.5,
                    picks=picks, baseline=None, preload=True)
mne.viz.plot_epochs(epochs, picks=picks)
mne.viz.plot_events(events, raw.info['sfreq'], raw.first_samp)


# Set up and fit the ICA
ica = mne.preprocessing.ICA(n_components=20, random_state=97, max_iter=800)
ica.fit(raw)

# ica.plot_components()

# Mark components for exclusion (example here is arbitrary; in practice, inspect components)
ica.exclude = [0, 1, 2]  # Adjust these indices based on your own ICA component inspection

# Plot the ICA components properties
# ica.plot_properties(raw, picks=ica.exclude)

# Apply the ICA to the raw data
raw_corrected = raw.copy()
ica.apply(raw_corrected)

# Plot the corrected data
raw_corrected.plot(duration=5, n_channels=30)


# Compute PSD using Multitaper method
psds, freqs = mne.time_frequency.psd_array_multitaper(raw_corrected.get_data(), sfreq=raw_corrected.info['sfreq'], fmin=1, fmax=50, n_jobs=1)

# Example: Average PSD for each channel
average_psd = psds.mean(axis=0)
plt.figure()
plt.plot(freqs, average_psd)
plt.xlabel('Frequency (Hz)')
plt.ylabel('Power Spectral Density (dB)')
plt.title('Average Power Spectral Density')

# Display all plots
plt.show()

# Define frequency bands
freq_bands = {'Delta': (1, 4), 'Theta': (4, 8), 'Alpha': (8, 12), 'Beta': (12, 30)}

# Compute average power in each band for each channel
band_powers = {}
for band, (low, high) in freq_bands.items():
    psds_band = psds[:, (freqs >= low) & (freqs <= high)].mean(axis=1)
    band_powers[band] = psds_band

# Print or store the band powers
for band, power in band_powers.items():
    print(f"{band} band power:\n {power}")


# Combine features into a matrix
features = np.array([band_powers[band] for band in freq_bands.keys()]).T

# Print the feature matrix
print("Feature matrix shape:", features.shape)
print("Feature matrix:\n", features)


# epochs = mne.Epochs(raw_corrected, events, event_id, tmin, tmax, proj=True, picks=picks, baseline=None, preload=True)

# csp = CustomCSP(n_components=4)
# lda = LDA()
# pipeline = Pipeline([('CSP', csp), ('LDA', lda)])
# scores = cross_val_score(pipeline, X, y, cv=5, scoring='accuracy', error_score='raise')
# print(f'{scores.tolist()}')
