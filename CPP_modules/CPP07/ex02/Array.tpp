/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:27:55 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/22 15:33:48 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL){}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	this->_size = copy._size;
	this->_array = new T[copy._size]();
	for (unsigned int i = 0; i < this->_size; ++i)
	{
		this->_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &a)
{
	if (this != &a)
	{
		if (this->_size != a._size)
		{
			delete[] this->_array;
			this->_array = new T[a._size];
			this->_size = a._size;
		}
		for (unsigned int i = 0; i <this->_size; ++i) {
			this->_array[i] = a._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size) {
		throw std::exception();
	}
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size()
{
	return this->_size;
}

