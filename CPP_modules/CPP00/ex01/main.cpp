/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:48:32 by marvin            #+#    #+#             */
/*   Updated: 2023/04/05 16:12:36 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

int	main()
{
	string		str;
	int			i = 0;
	PhoneBook	book;

	while (str.compare("EXIT") != 0)
	{
		cout << "Phonebook : ";
		cin >> str;
		if (str.compare("ADD") == 0)
		{
			book.add(i);
			i++;
		}
		else if (str.compare("SEARCH") == 0)
			book.search();
	}
	return (0);
}

