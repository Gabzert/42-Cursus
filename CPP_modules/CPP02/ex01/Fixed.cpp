/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:24:30 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/29 15:44:23 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

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

Fixed::Fixed(const int value)
{
	std::cout << "Int Constructor" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float Constructor" << std::endl;
	this->value = (int)roundf(value * (1 << this->bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << std::endl;
}

Fixed &Fixed::operator= (const Fixed &a)
{
	std::cout << "Assignment operator" << std::endl;
	if (this != &a)
		this->value = a.getRawBits();
	
	return(*this);
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

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->bits));
}

int Fixed::toInt( void ) const
{
	return(this->value >> this->bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
