/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:37:16 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/27 10:49:48 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "Just one argument, the RPN operation in one string" << std::endl;
		return (1);
	}
	try
	{
		int res = evaluateRPN(argv[1]);
		std::cout << res << std::endl;
	}
	catch(const std::exception& e) {}
	
	return (0);
}
