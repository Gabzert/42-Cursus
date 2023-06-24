/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:39:13 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/19 17:27:18 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	int _gradeSign;
	int _gradeExe;

public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExe);
	AForm(const AForm &copy);
	virtual AForm &operator=(const AForm &a);
	virtual ~AForm();
	
	std::string getName() const;
	bool getSign() const;
	int getGradeS() const;
	int getGradeX() const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("The grade you set is too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("The grade you set is too low");
			}
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("the form is not singed");
			}
	};

	void checkGrade(int grade);
	virtual void beSigned(Bureaucrat &bc);
	virtual void execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, const AForm &f);
