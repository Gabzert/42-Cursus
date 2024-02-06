#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>

double estimate_price(double mileage, double theta0, double theta1) {
    return theta0 + (theta1 * mileage);
}



int main()
{
	std::ifstream data;
	std::string tmp;
	double theta0;
	double theta1;
	double mileage;

	data.open("model-data.csv");
	if (!data.is_open())
	{
		std::cerr << "ERROR: could not open file" << std::endl;
		return 1;
	}
	getline(data, tmp);
	theta0 = std::atof(tmp.substr(0, tmp.find('|')).c_str());
	theta1 = std::atof(tmp.substr(tmp.find('|') + 1, tmp.length()).c_str());
	std::cout << "Insert mileage :";
	std::cin >> mileage;
	double km = (mileage - 22899) / (240000 - 22899);
	double price = estimate_price(km, theta0, theta1);
	std::cout << "Estimated price: " << price << std::endl;
	return (0);
}
