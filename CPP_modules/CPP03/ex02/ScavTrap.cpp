/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:54:42 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/24 10:18:08 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->Name = "n/a";
    this->Attack = 20;
    this->Energy = 50;
    this->HP = 100;
	std::cout << "ScavTrap reporting for duty!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Name = name;
	this->Attack = 20;
	this->Energy = 50;
	this->HP = 100;
	std::cout << "ScavTrap " << name << " reporting for duty!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = toCopy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs){
		this->Name = rhs.Name;
		this->Attack = rhs.Attack;
		this->HP = rhs.HP;
		this->Energy = rhs.Energy;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap out!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->Name << " guard mode : Active" << std::endl;
}
