/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:07:35 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/17 10:57:39 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Miao i am Cat" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &a)
{
	if (this != &a)
	{
		this->type = a.type;
		this->b = a.b;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "I am no longer Cat" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "*purrs*" << std::endl;
}
