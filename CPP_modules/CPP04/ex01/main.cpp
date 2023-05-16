/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:15:51 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/16 17:49:38 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal arr[10];
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
			arr[i] = Dog();
		else
			arr[i] = Cat();
	}
	delete j;
	delete i;

	return 0;
}
