/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:02:27 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/17 16:35:41 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Materia copy constructor called" << std::endl;
	*this = copy;
}

std::string const &AMateria::getType() const //Returns the materia type
{
	return (this->_type);
}

AMateria &AMateria::operator=(const AMateria &a)
{
	if (this != &a)
		this->_type = a._type;
	return (*this);
}

AMateria::~AMateria(){}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << this->getType() << " on " << target.getName() << " *" << std::endl;
}

