/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:37:16 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/28 12:07:14 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "Just one argument" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe(argc, argv);
	}
	catch(const std::exception& e) {}
	
	return (0);
}
