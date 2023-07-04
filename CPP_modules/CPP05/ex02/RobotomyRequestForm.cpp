/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:20:17 by gfantech          #+#    #+#             */
/*   Updated: 2023/07/03 11:34:21 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
	if (this != &a)
	{
		this->_target = a._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// Get a random number
	int random = rand() % 100;

	if (this->getSign())
	{
		if (executor.getGrade() <= this->getGradeX())
		{
			std::cout << "*bzzzz clank clonk zzzz zzz ping*" << std::endl;
			if (random > 50)
			{
				std::cout << this->_target << " has been robotomized successfully 🤖" << std::endl;
			}
			else
				std::cout << "ERROR: robotomization failed 💥" << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}
