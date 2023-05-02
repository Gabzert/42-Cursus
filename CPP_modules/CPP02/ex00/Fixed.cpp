/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:24:30 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/20 10:52:47 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = a;
}

Fixed & Fixed::operator= (const Fixed &a)
{
	std::cout << "Assignment operator" << std::endl;
	if (this != &a)
		this->value = a.value;
	
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits" << std::endl;
	return(this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits" << std::endl;
	this->value = raw;
}
