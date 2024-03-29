/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:16:05 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/17 11:38:25 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;
	
public:
	virtual Animal &operator=(const Animal &a);
	virtual	~Animal();

	std::string getType() const;

	virtual void makeSound() const = 0;
};

#endif
