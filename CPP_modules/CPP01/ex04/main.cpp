/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:32:32 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/19 14:18:10 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file;
	std::ofstream newFile;
	std::string temp;

	if (argc != 4)
	{
		std::cout << "Wrong number of parameters" << std::endl;
		return(1);
	}
	file.open(argv[1]);
	if (file.fail())
	{
		std::cout << "Error opening file" << std::endl;
		return(1);
	}
	temp = argv[1];
	temp.append(".replace");
	newFile.open(temp);
	if (newFile.fail())
	{
		std::cout << "Error opening file" << std::endl;
		return(1);
	}
	temp.clear();
	while (getline(file, temp))
	{
		size_t start = temp.find(argv[2], 0);
		if (start !=  std::string::npos)
		{
			temp.erase(start, s1.size());
			temp.insert(start, s2);
		}
		newFile << temp;
		newFile << std::endl;
	}
	return (0);
}
