/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:05:56 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/16 11:06:00 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	std::cout << "creo orda di 7 zombie" << std::endl;
	Zombie *horde = zombieHorde(7, "pippo");
	for (int i = 0; i < 7; i++) {
		horde[i].announce();
	}
	std::cout << "ora cancello tutto" << std::endl;
	delete [] horde;
}
