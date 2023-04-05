/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:02:15 by marvin            #+#    #+#             */
/*   Updated: 2023/04/05 16:40:11 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Contact
{
	private :

	int		id;
	string	name;
	string	last_name;
	string	nickname;
	string	number;
	string	secret;

	static int c_num;

	public:
	
	Contact() {this->id = -1;};

	void init(int id);

	int getId() const { return id; }
	void setId(int id_) { id = id_; }

	string getName() const { return name; }
	void setName(const string &name_) { name = name_; }

	string getLastName() const { return last_name; }
	void setLastName(const string &lastName) { last_name = lastName; }

	string getNickname() const { return nickname; }
	void setNickname(const string &nickname_) { nickname = nickname_; }

	string getNumber() const { return number; }
	void setNumber(int number_) { number = number_; }

	string getSecret() const { return secret; }
	void setSecret(const string &secret_) { secret = secret_; }

};


class PhoneBook
{
	public :

	PhoneBook() {};
	~PhoneBook() {};
	void add(int i);
	void search();

	private :

	Contact list[8];
};

#endif
