import numpy as np
from describe import get_data
learning_rate = 0.01
epochs = 1000



def train_model(data):
	# Initialize the weights
	num_features = len(data[0]) - 1
	weights = np.zeros(num_features)
	bias = 0

	# Train the model
	for epoch in range(epochs):
		for row in data:
			y = row[-1]
			x = row[:-1]
			z = np.dot(weights, x) + bias
			prediction = 1 / (1 + np.exp(-z))
			weights -= learning_rate * (prediction - y) * x
			bias -= learning_rate * (prediction - y)

	return weights, bias	
	

if __name__ == '__main__':
	# Load the data
	data = get_data('./datasets/dataset_train.csv')

	# Train the model
	weights, bias = train_model(data)

	# Save the model
	np.savez('weights', weights=weights, bias=bias)

