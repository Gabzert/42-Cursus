/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:43:31 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/11 14:11:33 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "I cast destroy undead on :" << this->name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": " << "BraiiiiiinnnnnzzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name )
{
	Zombie	*z = new Zombie(name);
	return (z);
}

void randomChump( std::string name )
{
	Zombie	z(name);
	z.announce();
}
