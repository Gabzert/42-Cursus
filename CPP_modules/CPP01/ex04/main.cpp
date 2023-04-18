/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:32:32 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/18 16:51:32 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(argv[1]);
	std::ofstream newFile;

	if (argc != 4)
		std::cout << "Wrong number of parameters" << std::endl;
	return (0);
}
