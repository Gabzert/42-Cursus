/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:50:34 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/24 10:23:51 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("n/a"), Attack(0), Energy(10), HP(10)
{
		std::cout << "ClapTrap assembled" << std::endl;
}


ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->Attack = 0;
	this->Energy = 10;
	this->HP = 10;
	std::cout << "ClapTrap " << name <<  " assembled" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = toCopy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs){
		this->Name = rhs.Name;
		this->Attack = rhs.Attack;
		this->HP = rhs.HP;
		this->Energy = rhs.Energy;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Energy > 0 || this->HP > 0)
	{
		this->Energy--;
		std::cout << "ClapTrap " << this->Name << " attacks " << target << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Energy > 0 || this->HP > 0)
	{
		this->HP -= amount;
		std::cout << "ClapTrap " << this->Name << " took " << amount << " damage" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy > 0 || this->HP > 0)
	{
		this->HP += amount;
		this->Energy--;
		std::cout << "ClapTrap " << this->Name << " repaired " << amount << " health" << std::endl;
	}
}
