/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:01:01 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/21 16:42:34 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char         ScalarConverter::_letter;
int          ScalarConverter::_num;
float        ScalarConverter::_fnum;
double       ScalarConverter::_dnum;


ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

int ScalarConverter::getNum()
{
	return(_num);
}

char ScalarConverter::getLetter()
{
	return(_letter);
}

float ScalarConverter::getFNum()
{
	return(_fnum);
}

double ScalarConverter::getDNum()
{
	return(_dnum);
}

bool isChar(std::string input)
{
	if (input.length() == 1 && std::isalpha(input[0]))
		return (true);
	else 
		return (false);
}

bool isNum(std::string input)
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
	{
        if (std::isalpha(*it))
		{
            return (false);
        }
    }
    return (true);
}

bool isFNum(std::string input)
{
	if (input.find('f') != std::string::npos && input.find('.') != std::string::npos)
		return (true);
	return (false);
}

bool isDNum(std::string input)
{
	if (input.find('.') != std::string::npos)
		return (true);
	return (false);
}

void ScalarConverter::convert(std::string input)
{
	if (isChar(input))
		convertChar(input);
	else if (isFNum(input))
		convertFNum(input);
	else if (isDNum(input))
		convertDNum(input);
	else if (isNum(input))
		convertNum(input);
	else if (( input.compare("nan") == 0 ) || ( input.compare("nanf") == 0 )
        || ( input.compare("+inf") == 0 ) || ( input.compare("+inff") == 0 ) 
        || ( input.compare("-inf") == 0 ) || ( input.compare("-inff") == 0 ))
    print(input);
	else
		throw NoConvertionException();
}
void ScalarConverter::convertChar(std::string input)
{
	_letter = input[0];
	_num = static_cast<int>(_letter);
	_fnum = static_cast<float>(_letter);
	_dnum = static_cast<double>(_letter);
	print(input);
}

void ScalarConverter::convertNum(std::string input)
{
	_num = std::atoi(input.c_str());
	_letter = static_cast<char>(_num);
	_fnum = static_cast<float>(_num);
	_dnum = static_cast<double>(_num);
	print(input);
}

void ScalarConverter::convertFNum(std::string input)
{
	_fnum = std::atof(input.c_str());
	_letter = static_cast<char>(_fnum);
	_num = static_cast<int>(_fnum);
	_dnum = static_cast<double>(_fnum);
	print(input);
}

void ScalarConverter::convertDNum(std::string input)
{
	_dnum = std::atof(input.c_str());
	_letter = static_cast<char>(_dnum);
	_num = static_cast<int>(_dnum);
	_fnum = static_cast<float>(_dnum);
	print(input);
}

void ScalarConverter::print(std::string input)
{
	std::cout << "char: ";
	fixChar(input);
	std::cout << "int: ";
	fixNum(input);
	std::cout << "float: ";
	fixFNum(input);
	std::cout << "double: ";
	fixDNum(input);
}

void ScalarConverter::fixChar(std::string input)
{
    if (( input.compare("nan") == 0 ) || ( input.compare("nanf") == 0 )
        || ( input.compare("+inf") == 0 ) || ( input.compare("+inff") == 0 ) 
        || ( input.compare("-inf") == 0 ) || ( input.compare("-inff") == 0 ))
    {
        std::cout << "Impossible";
    }
    else if (!std::isprint(_letter))
        std::cout << "Not displayable";
    else
        std::cout << "'" << _letter << "'";
    std::cout << std::endl;
}

void ScalarConverter::fixNum(std::string input)
{
	long test;
	test = std::atol(input.c_str());
    if (test > INT_MAX || test < INT_MIN
		|| ( input.compare("nan") == 0 ) || ( input.compare("nanf") == 0 )
        || ( input.compare("+inf") == 0 ) || ( input.compare("+inff") == 0 ) 
        || ( input.compare("-inf") == 0 ) || ( input.compare("-inff") == 0 ))
    {
        std::cout << "Impossible";
    }
    else
        std::cout << _num;
    std::cout << std::endl;
}

void ScalarConverter::fixFNum(std::string input)
{
    if (( input.compare("nan") == 0 ) || ( input.compare("nanf") == 0 ))
        std::cout << "nanf";
    else if(( input.compare("+inf") == 0 ) || ( input.compare("+inff") == 0 )) 
        std::cout << "+inff";
	else if(( input.compare("-inf") == 0 ) || ( input.compare("-inff") == 0 ))
	    std::cout << "-inff";
    else
	{
		if (_fnum - static_cast<int>(_fnum) == 0)
			std::cout << _fnum << ".0" << "f";
		else
        	std::cout << _fnum << "f";
	}
    std::cout << std::endl;
}

void ScalarConverter::fixDNum(std::string input)
{
    if (( input.compare("nan") == 0 ) || ( input.compare("nanf") == 0 ))
        std::cout << "nan";
    else if(( input.compare("+inf") == 0 ) || ( input.compare("+inff") == 0 )) 
        std::cout << "+inf";
	else if(( input.compare("-inf") == 0 ) || ( input.compare("-inff") == 0 ))
	    std::cout << "-inf";
    else
	{
		if (_dnum - static_cast<int>(_dnum) == 0)
			std::cout << _dnum << ".0";
		else
        	std::cout << _dnum;
	}
    std::cout << std::endl;
}

