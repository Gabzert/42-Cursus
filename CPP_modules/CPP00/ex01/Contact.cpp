/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:46:15 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/16 09:51:56 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::init(int id)
{
	std::string check;

	std::cin.ignore();
	while (this->name.empty())
	{
		std::cout << "Name : ";
		std::getline(std::cin, this->name);
	}
	while (this->last_name.empty())
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, this->last_name);
	}
	while (this->number.empty())
	{
		std::cout << "Number : ";
		std::getline(std::cin, this->number);
	}
	while (this->nickname.empty())
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, this->nickname);
	}
	while (this->secret.empty())
	{
		std::cout << "*Secret* : ";
		std::getline(std::cin, this->secret);
	}
    this->id = id;
}

int Contact::getId() const { return this->id; }
void Contact::setId(int id_) { this->id = id_; }

std::string Contact::getName() const { return this->name; }
void Contact::setName(const std::string &name_) { this->name = name_; }

std::string Contact::getLastName() const { return this->last_name; }
void Contact::setLastName(const std::string &lastName) { this->last_name = lastName; }

std::string Contact::getNickname() const { return this->nickname; }
void Contact::setNickname(const std::string &nickname_) { this->nickname = nickname_; }

std::string Contact::getNumber() const { return this->number; }
void Contact::setNumber(int number_) { this->number = number_; }

std::string Contact::getSecret() const { return this->secret; }
void Contact::setSecret(const std::string &secret_) { this->secret = secret_; }
