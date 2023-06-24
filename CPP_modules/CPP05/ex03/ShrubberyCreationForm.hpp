/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:51:44 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 10:46:45 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
	~ShrubberyCreationForm();


	void execute(Bureaucrat const &executor) const;
};
