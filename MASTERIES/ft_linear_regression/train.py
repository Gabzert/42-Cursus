import numpy as np
import matplotlib.pyplot as plot

def estimate_price(mileage, theta0, theta1):
    return theta0 + (theta1 * mileage)

def train_linear_regression(mileage, price, learning_rate, num_iterations):
    m = len(mileage)
    theta0, theta1 = 0, 0

    for _ in range(num_iterations):
        tmp_theta0 = learning_rate * (1 / m) * np.sum(estimate_price(mileage, theta0, theta1) - price)
        tmp_theta1 = learning_rate * (1 / m) * np.sum((estimate_price(mileage, theta0, theta1) - price) * mileage)

        theta0 -= tmp_theta0
        theta1 -= tmp_theta1

    return theta0, theta1

def getdata():
	data = np.genfromtxt("data.csv", delimiter=",", skip_header=1)
	m = len(data)
	km = np.array([1] * m, float)
	prices = np.array([1] * m, float)
	for i in range(len(data)) :
		if (i < m):
			km[i] = data[i][0]
			prices[i] = data[i][1]
	km = km.reshape(km.shape[0], 1)
	prices = prices.reshape(prices.shape[0], 1)
	normKm = km.copy()
	xmin = np.min(km)
	xmax = np.max(km)
	for i in range(len(normKm)):
		normKm[i] = (normKm[i] - xmin) / (xmax - xmin)
	return km, normKm, prices


if __name__ == '__main__':
	km, mileage_data, price_data = getdata()

	learning_rate = 0.07
	num_iterations = 1000

	theta0, theta1 = train_linear_regression(mileage_data, price_data, learning_rate, num_iterations)
	plot.scatter(km, price_data, marker='o')
	plot.plot(km, estimate_price(mileage_data, theta0, theta1), color='g')
	plot.xlabel("mileage")
	plot.ylabel("price")
	plot.title("Price Graph")
	plot.show()
	print(theta0, theta1)

	# Save theta0 and theta1 to a file for later use in prediction program
	np.save('theta_values.npy', np.array([theta0, theta1]))
