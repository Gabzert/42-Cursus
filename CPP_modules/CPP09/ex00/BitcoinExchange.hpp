/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:38:44 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/24 14:34:47 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <fstream>

typedef struct s_data
{
	std::string date;
	int index;
}	t_data;

class BitcoinExchange
{
private:
	BitcoinExchange();

public:
	BitcoinExchange(std::string dataFile, std::string inputFile);
	~BitcoinExchange();

	std::map<t_data, double> dataMap;
	std::map<t_data, double> inputMap;

	void printOut();
};
