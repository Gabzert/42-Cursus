/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:24:30 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/29 16:14:56 by gfantech         ###   ########.fr       */
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
	
	return (*this);
}

bool Fixed::operator< (const Fixed &a) const
{
	std::cout << "Minor operator" << std::endl;
	if (this != &a)
	{
		if (this->value < a.getRawBits())
			return (true);
		else
			return (false);
	}
	return (false);
}

bool Fixed::operator> (const Fixed &a) const
{
	std::cout << "Major operator" << std::endl;
	if (this != &a)
	{
		if (this->value > a.getRawBits())
			return (true);
		else
			return (false);
	}
	return (false);
}
bool Fixed::operator<= (const Fixed &a) const
{
	std::cout << "Minor/equals operator" << std::endl;
	if (this != &a)
	{
		if (this->value <= a.getRawBits())
			return (true);
		else
			return (false);
	}
	return (false);
}
bool Fixed::operator>= (const Fixed &a) const
{
	std::cout << "Major/equals operator" << std::endl;
	if (this != &a)
	{
		if (this->value >= a.getRawBits())
			return (true);
		else
			return (false);
	}
	return (false);
}

bool Fixed::operator== (const Fixed &a) const
{
	std::cout << "Equals operator" << std::endl;
	if (this != &a)
	{
		if (this->value == a.getRawBits())
			return (true);
		else
			return (false);
	}
	return (false);
}

bool Fixed::operator!= (const Fixed &a) const
{
	std::cout << "Different operator" << std::endl;
	if (this != &a)
	{
		if (this->value != a.getRawBits())
			return (true);
		else
			return (false);
	}
	return (false);
}

Fixed &Fixed::operator++ ()
{
	this->value++;
	return (*this);
}

Fixed &Fixed::operator++ (int)
{
	Fixed &old(*this);
	this->value++;
	return (old);
}

Fixed &Fixed::operator-- ()
{
	this->value--;
	return (*this);
}

Fixed &Fixed::operator-- (int)
{
	Fixed &old(*this);
	this->value--;
	return (old);
}

Fixed &Fixed::operator+ (const Fixed &a)
{
	if (this != &a)
		this->value = (int)roundf((this->toFloat() + a.toFloat()) * (1 << this->bits));
	
	return (*this);
}

Fixed &Fixed::operator- (const Fixed &a)
{
	if (this != &a)
		this->value = (int)roundf((this->toFloat() - a.toFloat()) * (1 << this->bits));
	
	return (*this);
}

Fixed &Fixed::operator* (const Fixed &a)
{
	if (this != &a)
		this->value = (int)roundf((this->toFloat() * a.toFloat()) * (1 << this->bits));
	
	return (*this);
}

Fixed &Fixed::operator/ (const Fixed &a)
{
	if (this != &a)
		this->value = (int)roundf((this->toFloat() / a.toFloat()) * (1 << this->bits));
	
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits" << std::endl;
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int Fixed::toInt( void ) const
{
	return (this->value >> this->bits);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first != second)
	{
		if (first < second)
			return (first);
		else
			return (second);
	}
	return (first);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first != second)
	{
		if (first < second)
			return (first);
		else
			return (second);
	}
	return (first);
}

Fixed &Fixed::max( Fixed &first, Fixed &second)
{
	if (first != second)
	{
		if (first > second)
			return (first);
		else
			return (second);
	}
	return (first);
}
const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first != second)
	{
		if (first > second)
			return (first);
		else
			return (second);
	}
	return (first);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
