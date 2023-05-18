/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:11:31 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/18 11:14:18 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : pool{NULL, NULL, NULL, NULL} {}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &a)
{
	if (this != &a)
		this->_type = a._type;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	int  i = 0;
	while (this->pool[i])
	{
		delete this->pool[i];
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *new_element)
{
	int i = 0;
	while (this->pool[i])
		i++;
	if (i < 4)
		this->pool[i] = new_element;
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (this->pool[i])
	{
		if (type == this->pool[i]->getType())
			return (this->pool[i]->clone());
		i++;
	}
	return (NULL);
}
