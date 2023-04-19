/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:19:34 by gabriele          #+#    #+#             */
/*   Updated: 2023/04/19 16:07:09 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string input = argv[1];
	Harl		karen;
	std::string cmd[4] = {"DEBUG","INFO","WARNING","ERROR"};
	int i = 0;

	if (argc != 2)
		return(0);
	while (i < 4 && input.compare(cmd[i]))
		i++;
	if (i == 4)
		std::cout << "*Obnoxious background screeaming*" << std::endl;
	else
	{
		while (i < 4)
		{
			std::cout << "[" << cmd[i] << "]" << std::endl;
			karen.complain(cmd[i]);
			i++;
			std::cout << std::endl;
		}
	}
	return (0);
}