/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:46:13 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 16:51:52 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Miao i am WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &a)
{
	if (this != &a)
	{
		this->type = a.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "I am no longer WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "*purrs*" << std::endl;
}