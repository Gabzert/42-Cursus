import numpy as np
import sys
import os
import csv
from logreg_train import forward_pass
from describe import get_data

# Prediction
def predict(X, weights, biases):
	y_pred = np.zeros((X.shape[0], 4), dtype=float)
	for k in range(X.shape[0]):
		for i in range(len(weights)):
			weight = weights[i]
			bias = biases[i]
			y_pred[k][i] = forward_pass(X[k], weight, bias)
	max_index = np.argmax(y_pred, axis=1)
	houses = ['Gryffindor', 'Hufflepuff', 'Ravenclaw', 'Slytherin']
	predicted_houses = [houses[i] for i in max_index]
	return predicted_houses


if __name__ == '__main__':

	if len(sys.argv) != 2:
		print("Usage: python3 logreg_predict.py <filename>")
		exit(1)
	filename = sys.argv[1]
	if not os.path.isfile(filename):
		print("File not found.")
		exit(1)
	data = get_data(filename)[0]
	data = data[1:, :]
	data = data[:, [1, 8, 9]]
	data = np.where(data == '', np.nan, data)
	X = data[:, 1:]
	X = X.astype(float)
	X = np.nan_to_num(X)
	# Load the models

	try:
		Gryffindor_weights = np.load('models/Gryffindor_weights.npy')
		Gryffindor_bias = np.load('models/Gryffindor_bias.npy')
		Hufflepuff_weights = np.load('models/Hufflepuff_weights.npy')
		Hufflepuff_bias = np.load('models/Hufflepuff_bias.npy')
		Ravenclaw_weights = np.load('models/Ravenclaw_weights.npy')
		Ravenclaw_bias = np.load('models/Ravenclaw_bias.npy')
		Slytherin_weights = np.load('models/Slytherin_weights.npy')
		Slytherin_bias = np.load('models/Slytherin_bias.npy')
	except FileNotFoundError:
		print("Models not found. Please train the models first.")
		exit(1)

	weights = [Gryffindor_weights, Hufflepuff_weights, Ravenclaw_weights, Slytherin_weights]
	biases = [Gryffindor_bias, Hufflepuff_bias, Ravenclaw_bias, Slytherin_bias]
	# Predict
	print("Predicting...")
	pred = predict(X, weights, biases)
	print("Predictions complete, writing to CSV file...")
	file_name = 'houses.csv'
	# Write the data to the CSV file
	with open(file_name, mode='w', newline='') as file:
		writer = csv.writer(file)
		writer.writerow(['Index', 'Hogwarts House'])  # Write the header
		for i, house in enumerate(pred):
			writer.writerow([i, house])
