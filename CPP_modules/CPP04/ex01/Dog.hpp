/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:19:56 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/16 16:18:34 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *b;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &a);
		~Dog();

		void makeSound() const;
};
