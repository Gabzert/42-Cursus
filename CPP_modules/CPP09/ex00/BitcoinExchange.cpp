/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:06 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/24 15:46:19 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdbool.h>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{
}



bool	isBisestile(int year)
{
	if (year % 4 == 0) {
			if (year % 100 != 0)
				return true;
			else {
				if (year % 400 == 0)
					return true;
				else
					return false;
			}
		}
	else
		return false;
}


bool checkDate(std::string date)
{
	int year;
	int month;
	int day;
	size_t pos = date.find("-");

	year = std::atoi(date.substr(0, pos).c_str());
	date.erase(0, pos + 1);
	pos = date.find("-");
	month = std::atoi(date.substr(0, pos).c_str());
	date.erase(0, pos + 1);
	pos = date.find("-");
	day = std::atoi(date.substr(0, pos).c_str());
	if (year < 1900 || year > 2023 || month > 12 || month < 1 || day < 1)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	else if (month == 2 && ((isBisestile(year) == true && day > 29 ) || (isBisestile(year) == false && day > 28)))
		return false;
	return true;
}

BitcoinExchange::BitcoinExchange(std::string dataFile, std::string inputFile)
{
	std::ifstream data;
	std::ifstream input;
	std::string tmp;
	int i = 0;

	data.open(dataFile);
	input.open(inputFile);
	if (!data.is_open() || !input.is_open())
	{
		std::cerr << "ERROR: could not open file" << std::endl;
		return ;
	}
	getline(data, tmp);
	if (tmp != "date,exchange_rate") {
		std::cout << "Error, data files first column is not 'date,exchange_rate'" << std::endl;
		data.close();
		return;
	}

	while (getline(data, tmp))
	{
		t_data info;
		info.index = i;
		info.date = tmp.substr(0, tmp.find(','));
		dataMap[info] = std::atof(tmp.substr(tmp.find(',') + 1, tmp.length()).c_str());
		i++;
	}
	i = 0;

	getline(input, tmp);
	if (tmp != "date | value") {
		std::cout << "Error, data files first column is not 'date | value'" << std::endl;
		data.close();
		return;
	}

	while (getline(input, tmp))
	{
		t_data info;
		info.index = i;
		info.date = tmp.substr(0, tmp.find(','));
		if (checkDate(info.date))
			info.date = "Error: Date format not valid";
		inputMap[info] = std::atof(tmp.substr(tmp.find(',') + 1, tmp.length()).c_str());
		if (inputMap[info] > 1000 || inputMap[info] < 0)
			info.date = "Error: Value not valid";
		i++;
	}
	
	data.close();
	input.close();
}

void BitcoinExchange::printOut()
{
    for (std::map<t_data, double>::const_iterator it = inputMap.begin(); it != inputMap.end(); it++)
    {
        const t_data& info = it->first;
        double inputValue = it->second;

        std::map<t_data, double>::const_iterator dataMapIt = dataMap.find(info);
        if (dataMapIt != dataMap.end())
        {
            double coinPrice = dataMapIt->second;
            double coinValue = inputValue * coinPrice;

            std::cout << info.date << " => " << inputValue << " = " << coinValue << std::endl;
        }
		else if (info.date.find("Error:"))
		{
			std::cerr << info.date << std::endl;
		}
    }
}
