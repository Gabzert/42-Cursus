/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:38:10 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 14:26:40 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
	if (this != &a)
	{
		this->_target = a._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign())
	{
		if (executor.getGrade() <= this->getGradeX())
		{
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}
