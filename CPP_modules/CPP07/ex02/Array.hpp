/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:05:56 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/22 15:11:31 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

template <class T>
class Array
{
private:
	unsigned int _size;
	T *_array;
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &copy);
	Array &operator=(const Array<T> &a);
	~Array();

	unsigned int size();
	T &operator[](unsigned int index);
};

#include "Array.tpp"
