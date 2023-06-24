/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:59:11 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/23 11:21:18 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &a)
{
	if (this != &a)
	{
		this->_N = a._N;
		this->_array = a._array;
	}
	return (*this);
}

Span::~Span()
{}

unsigned int Span::getSize() { return(this->_N); }

void Span::addNumber(int n)
{
	if (this->_array.size() >= this->_N)
		throw std::exception();
	else
	{
		this->_array.push_back(n);
	}
}

int Span::shortestSpan()
{
	if (this->_array.size() <= 1)
		throw std::exception();
	else
	{
		unsigned int ret = -1;
		unsigned int tmp;
		for (unsigned int i = 1; i < this->_array.size(); i++)
		{
			tmp = std::abs(this->_array[i - 1] - this->_array[i]);
			if (tmp < ret)
				ret = tmp;
		}
		return (ret);
	}
	return (-1);
}

int Span::longestSpan()
{
	if (this->_array.size() <= 1)
		throw std::exception();
	else
	{
		unsigned int ret = 0;
		unsigned int tmp;
		for (unsigned int i = 1; i < this->_array.size(); i++)
		{
			tmp = std::abs(this->_array[i - 1] - this->_array[i]);
			if (tmp > ret)
				ret = tmp;
		}
		return (ret);
	}
	return (-1);
}
