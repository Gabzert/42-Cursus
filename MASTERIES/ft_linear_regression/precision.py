from train import getdata, estimate_price
import numpy as np
import os



km, mileage_data, price_data = getdata()
if not 'theta_values.npy' in os.listdir():
	print("You need to train the model first. Run train.py")
	exit(1)
theta_values = np.load('theta_values.npy')
theta0, theta1 = theta_values[0], theta_values[1]
# MSE = ((np.sum((price_data - estimate_price(mileage_data, theta0, theta1)) ** 2)) / len(km))
max_price = np.max(price_data)
min_price = np.min(price_data)
RMSE = 100 * (1 - ((np.sum((price_data - estimate_price(mileage_data, theta0, theta1))**2) / len(km)) ** 0.5) / (max_price - min_price))

print("Precision: ", round(RMSE, 2), "%")
