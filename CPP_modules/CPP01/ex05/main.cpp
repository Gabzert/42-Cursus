/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:19:34 by gabriele          #+#    #+#             */
/*   Updated: 2023/04/19 15:33:57 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string input;
	Harl		karen;

	while (input.compare("exit"))
	{
		std::cout << "level: ";
		std::cin >> input;
		karen.complain(input);
	}
	return (0);
}