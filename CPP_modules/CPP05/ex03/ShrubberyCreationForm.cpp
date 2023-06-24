/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:15:00 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 14:25:29 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
	if (this != &a)
	{
		this->_target = a._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream file;
	
	if (this->getSign())
	{
		if (executor.getGrade() <= this->getGradeX())
		{
			std::ofstream file((this->getName() + "_shrubbery").c_str());

			file <<	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⢰⣶⡎⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⢱⣶⣶⣶⣶⣶⣶⡆⠀⠀"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⠘⠛⢣⣤⣤⣤⣤⣤⣤⣤⣤⡄⠀⠈⠛⠛⠛⠛⣿⣿⡇⠀⠀"<< std::endl;
			file <<	"	⠀⠀⠀⠀⠀⠀⠀⠘⠛⠛⠛⠛⠛⠛⠛⠛⢣⣤⡄⠀⠀⠀⠀⣿⣿⡇⠀⠀"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡸⠿⢇⣀⣀⠀⠀⠻⠿⢃⣀⡀"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠿⠿⢇⣀⡸⠿⠿⣀⣀⠀⠀⢸⣿⡇"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⢸⣿⡇⠀⠀⣿⣿⠀⠀⢸⣿⡇"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⣿⣿⡇⠀⠀⠀⠀⣿⣿⠀⠀⢸⣿⡇"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⢸⣿⡇"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⠀⠀⢰⣶⡎⠉⠱⣶⣶⠉⠉⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⢸⣿⡇"<< std::endl;
			file <<	"⠀⠀⠀⠀⠀⣶⣶⡌⠉⢱⣶⡆⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⣴⣶⡎⠉⠁"<< std::endl;
			file <<	"⠀⠀⠀⣤⣤⠛⠛⢡⣤⡜⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠃⠀⠀"<< std::endl;
			file << "⢀⣤⣤⠛⠛⣤⣤⡘⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
			file <<	"⢸⣿⣿⣀⣀⠿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
			file <<	"⠸⠿⠿⠿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
			file.close();
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}
