/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:02:15 by marvin            #+#    #+#             */
/*   Updated: 2023/03/21 12:02:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

#include <iostream>

using namespace std;

class Contact
{
	private :

	int id;
	string name;
	string last_name;
	string nickname;
	int	number;
	string secret;

	static int c_num;

	public:
		
	Contact(int id_, const string& name_, const string& last_name_, const string& nickname_, int number_, const string& secret_);

	int getId() const { return id; }
	void setId(int id_) { id = id_; }

	string getName() const { return name; }
	void setName(const string &name_) { name = name_; }

	string lastName() const { return last_name; }
	void setLastName(const string &lastName) { last_name = lastName; }

	string getNickname() const { return nickname; }
	void setNickname(const string &nickname_) { nickname = nickname_; }

	int getNumber() const { return number; }
	void setNumber(int number_) { number = number_; }

	string getSecret() const { return secret; }
	void setSecret(const string &secret_) { secret = secret_; }

};


class PhoneBook
{
	public :

	void add(Contact new_contact);
	void search();

	private :

	Contact list[8];
};

#endif