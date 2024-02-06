#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h> 

double estimate_price(double mileage, double theta0, double theta1) {
    return theta0 + (theta1 * mileage);
}

void train_linear_regression(std::vector<double>& mileage, std::vector<double>& price, double learning_rate, int num_is, double& theta0, double& theta1) {
    int m = mileage.size();

	for (int iter = 0; iter < num_is; iter++){
		long double sum0 = 0 , sum1 = 0 , step0 = 0 , step1 = 0;
		for (int i = 0; i < m; ++i) {
			double tmp_theta0 = (estimate_price(mileage[i], theta0, theta1) - price[i]);
			double tmp_theta1 = ((estimate_price(mileage[i], theta0, theta1) - price[i]) * mileage[i]);

			sum0 += tmp_theta0;
			sum1 += tmp_theta1;
		}
		sum0 /= m;
		sum1 /= m;
		step0 = learning_rate * sum0; // step size
		step1 = learning_rate * sum1; // step size
        if (iter > 0 && (std::abs(step0) < 0.001 && std::abs(step1) < 0.001)) {
			std::cout << "Terminato\n";
            break;
        }
		theta0 -= step0;
		theta1 -= step1;
	}
}

void normalize_features(std::vector<double>& data) {
    double min_data = *std::min_element(data.begin(), data.end());
    double max_data = *std::max_element(data.begin(), data.end());

    for (size_t i = 0; i < data.size(); ++i) {
        data[i] = (data[i] - min_data) / (max_data - min_data);
    }
}

void get_data(std::vector<double> &mileage_data, std::vector<double> &price_data){
	std::ifstream data;
	std::string tmp;

	data.open("data.csv");
	if (!data.is_open())
	{
		std::cerr << "ERROR: could not open file" << std::endl;
		return ;
	}
	getline(data, tmp);
	if (tmp != "km,price") {
		std::cerr << "Error, data files first column is not 'date,exchange_rate'" << std::endl;
		data.close();
		return;
	}
	while (getline(data, tmp))
	{
		mileage_data.push_back(std::atof(tmp.substr(0, tmp.find(',')).c_str()));
		price_data.push_back(std::atof(tmp.substr(tmp.find(',') + 1, tmp.length()).c_str()));
	}
}


int main() {

    std::vector<double> mileage_data;
    std::vector<double> price_data;
	get_data(mileage_data, price_data);

	normalize_features(mileage_data);
	// normalize_features(price_data);
    double learning_rate = 0.03;
    int num_is = 1000;

    double theta0 = 1.0, theta1 = 1.0;

    train_linear_regression(mileage_data, price_data, learning_rate, num_is, theta0, theta1);

	std::ofstream output("model-data.csv");

	if (output.is_open()) {
		output << theta0 << "|" << theta1; 
		output.close();
	}
	else {
		std::cerr << "Error opening file\n";
	}

    std::cout << "Theta0: " << theta0 << ", Theta1: " << theta1 << std::endl;

    return 0;
}
