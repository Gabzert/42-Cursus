/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:19:16 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 11:19:55 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
	~RobotomyRequestForm();


	void execute(Bureaucrat const &executor) const;
};
