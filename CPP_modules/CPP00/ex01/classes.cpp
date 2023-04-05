/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:07:14 by marvin            #+#    #+#             */
/*   Updated: 2023/04/05 17:40:16 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

void	get_contact(Contact c)
{
	cout << "Index: " << c.getId() << endl;
	cout << "Name: " << c.getName() << endl;
	cout << "Lastname: " << c.getLastName() << endl;
	cout << "Number: " << c.getNumber() << endl;
	cout << "Nickname: " << c.getNickname() << endl;
	cout << "Secret: " << c.getSecret() << endl;
}

string	truncate(string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

void	print_contacts(Contact c)
{
	cout << "|" << setw(10) << c.getId() << "|";
	cout << setw(10) << truncate(c.getName()) << "|";
	cout << setw(10) << truncate(c.getLastName()) << "|";
	cout << setw(10) << truncate(c.getNickname()) << "|";
	cout << endl;
}

void Contact::init(int id)
{
	string check;

	while (this->name.empty())
	{
		cout << "Name : ";
		getline(cin, this->name);
	}
	while (this->last_name.empty())
	{
		cout << "Last Name : ";
		getline(cin, this->last_name);
	}
	while (this->number.empty())
	{
		cout << "Number : ";
		getline(cin, this->number);
	}
	while (this->nickname.empty())
	{
    cout << "Nickname : ";
    getline(cin, this->nickname);
	}
	while (this->secret.empty())
	{
    cout << "*Secret* : ";
    getline(cin, this->secret);
	}
    this->id = id;
}

void PhoneBook::add(int i)
{
    this->list[i % 8].init(i);
}

void PhoneBook::search()
{
    int		i = 0;
   	string	index;

    while (i < 8 && this->list[i].getId() != -1)
    {
		print_contacts(this->list[i]);
        i++;
    }
	do
	{
		cout << "Inserire indice di ricerca :";
		cin >> index;
		if ((stoi(index) > 7 || stoi(index) < 0) || this->list[stoi(index)].getId() == -1)
			cout << "input non valido" << endl;
	}
	while(stoi(index) > 7 || stoi(index) < 0 || this->list[stoi(index)].getId() == -1);
	get_contact(this->list[stoi(index)]);
}

