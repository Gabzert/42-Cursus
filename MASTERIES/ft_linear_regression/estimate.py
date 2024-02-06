import numpy as np

def estimate_price(mileage, theta0, theta1):
    return theta0 + (theta1 * mileage)

# Load the saved theta values
theta_values = np.load('theta_values.npy')
theta0, theta1 = theta_values[0], theta_values[1]
# Example usage:
user_input_mileage = float(input("Enter the mileage of the car: "))
km = (user_input_mileage - 22899) / (240000 - 22899)
predicted_price = estimate_price(km, theta0, theta1)

print(f"The estimated price for a car with mileage {user_input_mileage} is: {predicted_price}")
