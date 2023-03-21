/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:48:32 by marvin            #+#    #+#             */
/*   Updated: 2023/03/21 11:48:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

int	main(int argc, char **argv)
{
	string str;
	string name;
	string surname;
	string number;
	PhoneBook book;

	while (1)
	{
		cin >> str;
		if (str.compare("ADD") == 0)
		{
			cout << "Name : ";
			cin >> name;
			cout << "Last Name : ";
			cin >> surname;
			cout << "Number : ";
			cin >> number;

		}
		else if (str.compare("SEARCH") == 0)
		{

		}
		else if (str.compare("EXIT"))
			return (0);
	}
	return (0);
}

