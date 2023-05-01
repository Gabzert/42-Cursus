/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:02:26 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 14:18:12 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->Name = name;
	ClapTrap::Name = name + "_clap_name";

	this->HP = FragTrap::HP;
	this->Energy = ScavTrap::Energy;
	this->Attack = FragTrap::Attack;

	std::cout << "DiamondTrap " << name << " coming in hot!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy) : ClapTrap(toCopy), ScavTrap(toCopy), FragTrap(toCopy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = toCopy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs){
		this->Name = rhs.Name;
		this->Attack = rhs.Attack;
		this->HP = rhs.HP;
		this->Energy = rhs.Energy;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap out!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Hello meatbag i'm " << this->Name << " also known as " << this->ClapTrap::Name << std::endl;
}