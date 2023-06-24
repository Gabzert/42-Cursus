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

AForm::AForm(std::string name, int gradeSign, int gradeExe): _name(name), _isSigned(false) {

	checkGrade(gradeSign);
	checkGrade(gradeExe);
	this->_gradeSign = gradeSign;
	this->_gradeExe = gradeExe;
}

AForm::AForm(const AForm &copy){
	*this = copy;
}

AForm &AForm::operator=(const AForm &a){
	if (this != &a)
	{
		this->_gradeSign = a._gradeSign;
		this->_gradeExe = a._gradeExe;
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
