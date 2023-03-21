/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:07:14 by marvin            #+#    #+#             */
/*   Updated: 2023/03/21 14:07:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

void PhoneBook::add(Contact new_contact)
{
	int	older;
    for(int i = 0; i < 8; i++)
	{
        if(list[i].getId() == 0)
		{
            list[i] = new_contact;
            break;
        }
    }
	
}

Contact::Contact(int id_, const string& name_, const string& last_name_, const string& nickname_, int number_, const string& secret_) :
            id(id_), name(name_), last_name(last_name_), nickname(nickname_), number(number_), secret(secret_)
{
	Contact::c_num++;
}

int	Contact::c_num = 0;