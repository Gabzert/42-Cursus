/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:11:14 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/24 15:36:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "One paramater, input file" << std::endl;
		exit(1);
	}
	std::string dataFile = "data.csv";
	std::string inputFile = argv[1];
	BitcoinExchange calc(dataFile, inputFile);
	calc.printOut();
}
