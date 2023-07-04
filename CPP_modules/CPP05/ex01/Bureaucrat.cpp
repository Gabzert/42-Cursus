/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:53:31 by gfantech          #+#    #+#             */
/*   Updated: 2023/07/03 11:09:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("buro"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
	if (this != &a)
	{
		this->_grade = a._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you set is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you set is too low");
}

void Bureaucrat::promote()
{
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::demote()
{
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getSign())
		std::cerr << this->_name << " couldn’t sign " << f.getName() << " because is already signed" << std::endl;
	else
	{
		try
		{
			f.beSigned(*this);
			std::cout << this->_name << " signed " << f.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << this->_name << " couldn’t sign " << f.getName() << " because their grade was too low" << '\n';
		}
	}
		
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc)
{
	out << bc.getName() << " bureaucrat grade " << bc.getGrade();
	return (out);
}
