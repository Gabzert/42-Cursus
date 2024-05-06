import numpy as np
from describe import get_data
learning_rate = 0.01
epochs = 1000

# Initialize parameters
def initialize_parameters(n_features):
		# Initialize weights and intercept to zeros
		weights = np.zeros((n_features, 1))
		bias = 0
		return weights, bias

# Loss function (binary cross-entropy) -> log(likelihood)
def compute_loss(y_pred, y_true):
		return -np.mean(y_true * np.log(y_pred) + (1 - y_true) * np.log(1 - y_pred))






# Update parameters
def update_parameters(weights, bias, dw, db, learning_rate):
		weights -= learning_rate * dw
		bias -= learning_rate * db
		return weights, bias



# Sigmoid function -> p(x) = 1 / e^-(b_0 + sum_n(b_n * x_n))
def sigmoid(z):
		return 1 / (1 + np.exp(-z))


# Forward pass
def forward_pass(X, weights, bias):
		z = np.dot(X, weights) + bias
		return sigmoid(z)


# Gradient descent
def gradient_descent(X, y_true, y_pred):
		dw = np.dot(X.T, (y_pred - y_true)) / len(y_true)
		db = np.mean(y_pred - y_true)
		return dw, db

# Model training
def train_model(X_train, y_train, num_iterations, learning_rate, house):
		n_features = X_train.shape[1]
		weights, bias = initialize_parameters(n_features)
		y_train = (y_train == house).astype(int)
		for i in range(num_iterations):
				y_pred = forward_pass(X_train, weights, bias)
				loss = compute_loss(y_pred, y_train)
				dw, db = gradient_descent(X_train, y_train, y_pred)
				weights, bias = update_parameters(weights, bias, dw, db, learning_rate)
				if i % 100 == 0:
						print(f"Iteration {i}, Loss: {loss}")
		return weights, bias



# Assuming X_train, X_test are feature matrices and y_train, y_test are target vectors
# Example usage

if __name__ == '__main__':
	# Load the data
	data = get_data('./datasets/dataset_train.csv')[0]
	data = data[1:, :]

	# Take only the classes we consider, in this case "Defense Against the Dark Arts" and "Herbology"
	data = data[:, [0, 8, 9]]

	# Split the data into features and target
	X = data[:, 0:]
	y = data[:, 0]

	houses = ['Gryffindor', 'Hufflepuff', 'Ravenclaw', 'Slytherin']

	for house in houses:
		# Train the models
		weights, bias = train_model(X, y, epochs, learning_rate, house)
		# Save the models
		np.savez(f'./models/logreg_{house}.npz', weights=weights, bias=bias)













# # Prediction
# def predict(X, weight, bias):
# 		y_pred = forward_pass(X, weight, bias)


# # Model evaluation
# def evaluate_model(X_test, y_test, weight, bias):
# 		y_pred = predict(X_test, weight, bias)
# 		accuracy = np.mean(y_pred == y_test)
# 		return accuracy
# 		return (y_pred > 0.5).astype(int)
