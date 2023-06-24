/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:33:06 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/23 14:34:25 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack &copy) {*this = copy;}
	MutantStack &operator=(MutantStack &a) 
	{
		if (this != &a)
			this->c = a.c;
		return (*this);
	}

    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }
};
