/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:07:14 by marvin            #+#    #+#             */
/*   Updated: 2023/04/04 17:40:09 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

string  get_contact(Contact c)
{
    string str;

    str = c.getId() + "|" + c.getName() + "|" + c.getLastName() + "|" + c.getNickname();
    return (str);
}

void Contact::init(int id)
{
    cout << "Name : ";
    getline(cin, this->name);
    cout << "Last Name : ";
    getline(cin, this->last_name);
    cout << "Number : ";
    getline(cin, this->number);
    cout << "Nickname : ";
    getline(cin, this->nickname);
    cout << "*Secret* : ";
    getline(cin, this->secret);
    this->id = id;
}

void PhoneBook::add(int i)
{
    this->list[i % 8].init(i);
}

void PhoneBook::search()
{
    int i = 0;
    string str;
    Contact list[8] = this->getList();

    while (i < 8)
    {
        str = get_contact(list[i]);
        cout << str;
        i++;
    }
}

