/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:46:34 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/15 11:54:46 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str: "<< &str << std::endl << "stringPTR: " << stringPTR << std::endl << "stringREF: " << &stringREF << std::endl;
	std::cout << "str: "<< str << std::endl << "stringPTR: " << *stringPTR << std::endl << "stringREF: " << stringREF << std::endl;
	return (0);
}
