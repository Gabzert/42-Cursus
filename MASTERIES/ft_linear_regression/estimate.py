import numpy as np
import os
from train import getdata

def estimate_price(mileage, theta0, theta1):
    return theta0 + (theta1 * mileage)

# Load the saved theta values
if __name__ == '__main__':
	if not 'theta_values.npy' in os.listdir():
		print("You need to train the model first. Run train.py")
		exit(1)
	theta_values = np.load('theta_values.npy')
	theta0, theta1 = theta_values[0], theta_values[1]
	# Example usage:
	try:
		user_input_mileage = float(input("Enter the mileage of the car: "))
	except ValueError:
		print("Please enter a valid number")
		exit(1)
	# Normalize the input mileage
	mileages = getdata()
	min = np.min(mileages)
	max = np.max(mileages)
	km = (user_input_mileage - min) / (max - min)
	predicted_price = estimate_price(km, theta0, theta1)
	if predicted_price < 0:
		print("The estimated price is negative. If the mileage is very high, the model may not be accurate.")
		exit(1)
	print(f"The estimated price for a car with mileage {user_input_mileage} is: {predicted_price}")
