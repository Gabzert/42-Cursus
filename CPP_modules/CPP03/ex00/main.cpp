/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:15:46 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 09:37:11 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap CT("CT");
	ClapTrap Jerry("Jerry");

	CT.attack("Jerry");
	Jerry.takeDamage(0);
	Jerry.beRepaired(10);
	for (size_t i = 0; i < 5; i++)
	{
		Jerry.attack("CT");
		CT.takeDamage(0);
	}
}