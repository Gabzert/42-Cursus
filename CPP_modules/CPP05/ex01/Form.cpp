/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:29 by gfantech          #+#    #+#             */
/*   Updated: 2023/07/03 11:32:29 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(): _name("n/a"), _isSigned(false), _gradeSign(150), _gradeExe(150){}

Form::Form(std::string name, int gradeSign, int gradeExe): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExe(gradeExe){
	if (gradeSign < 1)
		throw GradeTooHighException();
	if (gradeSign > 150)
		throw GradeTooLowException();
	if (gradeExe < 1)
		throw GradeTooHighException();
	if (gradeExe > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy): _gradeSign(copy._gradeSign), _gradeExe(copy._gradeExe){
	*this = copy;
}

Form &Form::operator=(const Form &a){
	if (this != &a)
	{
		this->_isSigned = a._isSigned;
	}
	return (*this);
}

Form::~Form(){}

std::string Form::getName() const{
	return (this->_name);
}

bool Form::getSign() const{
	return (this->_isSigned);
}

int Form::getGradeS() const{
	return (this->_gradeSign);
}

int Form::getGradeX() const{
	return (this->_gradeExe);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade you set is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade you set is too low");
}

void Form::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() <= this->_gradeSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << " " << f.getGradeS() << " " << f.getGradeX() << " " << f.getSign();
	return (out);
}
