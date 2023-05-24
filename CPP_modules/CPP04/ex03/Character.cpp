/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:19:48 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/24 09:48:07 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : inventory{NULL, NULL, NULL, NULL} {}

Character::Character(const std::string name) : inventory{NULL, NULL, NULL, NULL}
{
	this->_name = name;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character &Character::operator=(const Character &a)
{
	int i = 0;
	if (this != &a)
	{
		this->_name = a._name;
		while (a.inventory[i])
		{
			this->inventory[i] = a.inventory[i];
			i++;
		}
	}
	return(*this);
}

Character::~Character() 
{
	int  i = 0;
	while (this->inventory[i])
	{
		delete this->inventory[i];
		i++;
	}
}


std::string const & Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
		return;
	while (this->inventory[i])
		i++;
	if (i < 3)
		this->inventory[i] = m;
}

void Character::unequip(int idx)
{
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx < 4 && idx > -1) && this->inventory[idx])
		this->inventory[idx]->use(target);
	std::cout << "Cannot use" << std::endl;
 }
