/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:07:14 by marvin            #+#    #+#             */
/*   Updated: 2023/05/16 10:00:50 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	get_contact(Contact c)
{
	std::cout << "Index: " << c.getId() << std::endl;
	std::cout << "Name: " << c.getName() << std::endl;
	std::cout << "Lastname: " << c.getLastName() << std::endl;
	std::cout << "Number: " << c.getNumber() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Secret: " << c.getSecret() << std::endl;
}

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

void	print_contacts(Contact c)
{
	std::cout << "|" << std::setw(10) << c.getId() << "|";
	std::cout << std::setw(10) << truncate(c.getName()) << "|";
	std::cout << std::setw(10) << truncate(c.getLastName()) << "|";
	std::cout << std::setw(10) << truncate(c.getNickname()) << "|";
	std::cout << std::endl;
}

void PhoneBook::add(int i)
{
    this->list[i % 8].init(i);
}

void PhoneBook::search()
{
    int		i = 0;
   	std::string	index;

    while (i < 8 && this->list[i].getId() != -1)
    {
		print_contacts(this->list[i]);
        i++;
    }
	do
	{
		std::cout << "Inserire indice di ricerca :";
		std::cin >> index;
		if ((stoi(index) > 7 || stoi(index) < 0) || this->list[stoi(index)].getId() == -1)
			std::cout << "input non valido" << std::endl;
	}
	while(stoi(index) > 7 || stoi(index) < 0 || this->list[stoi(index)].getId() == -1);
	get_contact(this->list[stoi(index)]);
}
