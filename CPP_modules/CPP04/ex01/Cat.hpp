/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:20:05 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/16 16:18:32 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *b;
	
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &a);
		~Cat();
		
		void makeSound() const;
};


