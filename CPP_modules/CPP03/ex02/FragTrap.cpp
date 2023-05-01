/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:40:18 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 11:45:21 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Name = name;
	this->Attack = 30;
	this->Energy = 100;
	this->HP = 100;
	std::cout << "FragTrap " << name << " ready to roll!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = toCopy;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs){
		this->Name = rhs.Name;
		this->Attack = rhs.Attack;
		this->HP = rhs.HP;
		this->Energy = rhs.Energy;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap out!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Give me 5! 🖐" << std::endl;
}