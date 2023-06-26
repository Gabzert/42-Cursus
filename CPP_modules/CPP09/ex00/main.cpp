/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:11:14 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/26 12:33:11 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "One paramater, input file" << std::endl;
		return (1);
	}
	std::string dataFile = "data.csv";
	std::string inputFile = argv[1];
	BitcoinExchange calc(dataFile, inputFile);
	calc.printOut();
	return (0);
}
