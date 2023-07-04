/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:29 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/19 17:33:37 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("n/a"), _isSigned(false), _gradeSign(150), _gradeExe(150){}

AForm::AForm(std::string name, int gradeSign, int gradeExe): _name(name), _isSigned(false), _gradeSign(gradeSign),_gradeExe(gradeExe){
	if (gradeSign < 1)
		throw GradeTooHighException();
	if (gradeSign > 150)
		throw GradeTooLowException();
	if (gradeExe < 1)
		throw GradeTooHighException();
	if (gradeExe > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy): _gradeSign(copy._gradeSign),_gradeExe(copy._gradeExe){
	*this = copy;
}

AForm &AForm::operator=(const AForm &a){
	if (this != &a)
	{
		this->_isSigned = a._isSigned;
	}
	return (*this);
}

AForm::~AForm(){}

std::string AForm::getName() const{
	return (this->_name);
}

bool AForm::getSign() const{
	return (this->_isSigned);
}

int AForm::getGradeS() const{
	return (this->_gradeSign);
}

int AForm::getGradeX() const{
	return (this->_gradeExe);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade you set is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade you set is too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("the form is not singed");
}

void AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() <= this->_gradeSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << " " << f.getGradeS() << " " << f.getGradeX() << " " << f.getSign();
	return (out);
}
