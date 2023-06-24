/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:04:50 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 15:32:31 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &a)
{
    *this = a;
    return (*this);
}

Intern::~Intern(){}

AForm *makeShrubbery(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *makeRobotomy(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *makePardon(const std::string target)
{
    return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    AForm *formPtr = NULL;

    AForm* (*forms[3])(const std::string target) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePardon
    };

    while (i < 3)
    {
        if (names[i] == form)
            break;
        i++;
    }

    if (i == 3)
        std::cerr << "ERROR: The form name passed as parameter doesn’t exist" << std::endl;
    else
    {
        std::cout << "Intern creates " << target << " " << form << " form" << std::endl;
        formPtr = forms[i](target);
    }
    return (formPtr);
}

