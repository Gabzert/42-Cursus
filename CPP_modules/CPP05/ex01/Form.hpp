/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:39:13 by gfantech          #+#    #+#             */
/*   Updated: 2023/07/03 11:24:31 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExe;

public:
	Form();
	Form(std::string name, int gradeSign, int gradeExe);
	Form(const Form &copy);
	Form &operator=(const Form &a);
	~Form();
	
	std::string getName() const;
	bool getSign() const;
	int getGradeS() const;
	int getGradeX() const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};	

	void beSigned(Bureaucrat &bc);

};

std::ostream &operator<<(std::ostream &out, const Form &f);
