/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:45:30 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/21 15:08:18 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include <sstream>
#include <string>
#include <stdexcept>

class ScalarConverter
{
private:
	static int _num;
	static char _letter;
	static float _fnum;
	static double _dnum;

	static void convertChar(std::string input);
	static void convertNum(std::string input);
	static void convertFNum(std::string input);
	static void convertDNum(std::string input);

	static void print(std::string input);
	static void fixChar(std::string input);
	static void fixNum(std::string input);
	static void fixFNum(std::string input);
	static void fixDNum(std::string input);

	class NoConvertionException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("cannot convert");
			}
	};


public:
	ScalarConverter();
	~ScalarConverter();

	static void convert(std::string input);

	static int getNum();
	static char getLetter();
	static float getFNum();
	static double getDNum();
	
};
