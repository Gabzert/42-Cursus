/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:37:19 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/20 11:37:52 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
	~PresidentialPardonForm();


	void execute(Bureaucrat const &executor) const;
};
