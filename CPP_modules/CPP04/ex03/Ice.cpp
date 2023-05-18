/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:11:28 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/17 16:37:24 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	std::cout << "ICE copy constructor called" << std::endl;
	*this = copy;
}

Ice &Ice::operator=(const Ice &a)
{
	if (this != &a)
		this->_type = a._type;
	return (*this);
}

Ice::~Ice(){}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
