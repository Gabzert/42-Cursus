/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:22:02 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 16:17:15 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
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
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "I am no longer Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}