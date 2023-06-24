/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:36 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 15:32:21 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <unistd.h>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand((unsigned) std::time(NULL));
    try
    {
        Bureaucrat Herm("Hermes", 2);
        Intern intern;
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Bender");
        AForm *form3;

        std::cout << std::endl;
        Herm.signForm(form1);
        Herm.executeForm(form1);
        std::cout << std::endl;
        Herm.signForm(form2);
        Herm.executeForm(form2);
        usleep(10);
        Herm.executeForm(form2);
        usleep(10);
        Herm.executeForm(form2);
        usleep(10);
        Herm.executeForm(form2);
        std::cout << std::endl;
        form3 = intern.makeForm("presidential pardon", "Giovanni");
        Herm.signForm(*form3);
        Herm.executeForm(*form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
