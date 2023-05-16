/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:42:52 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/16 09:51:57 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private :

	int		id;
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	static int c_num;

	public:
	
	Contact() {this->id = -1;};

	void init(int id);

	int getId() const;
	void setId(int id_);

	std::string getName() const;
	void setName(const std::string &name_);
	std::string getLastName() const;
	void setLastName(const std::string &lastName);

	std::string getNickname() const;
	void setNickname(const std::string &nickname_);

	std::string getNumber() const;
	void setNumber(int number_);

	std::string getSecret() const;
	void setSecret(const std::string &secret_);

};

#endif
