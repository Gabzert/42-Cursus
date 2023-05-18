/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:22:02 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/17 10:56:47 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->b = new Brain();
	std::cout << "Woof i am dog" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &a)
{
	if (this != &a)
	{
		this->type = a.type;
		this->b = a.b;
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->b;
	std::cout << "I am no longer Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}
