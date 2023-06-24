/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:36 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/19 17:38:10 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat jack("jack", 24);
	Bureaucrat emma("emma", 85);
	Form imu("I.M.U", 43, 20);

	try
	{
		std::cout << jack << std::endl;
		jack.promote();
		jack.promote();
		std::cout << jack << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		emma.signForm(imu);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		jack.signForm(imu);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		jack.signForm(imu);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
