/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:15:46 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 15:06:06 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap CT("CT");
	DiamondTrap Jerry("Jerry");

	CT.attack("Jerry");
	Jerry.takeDamage(10);
	Jerry.beRepaired(10);
	Jerry.attack("CT");
	CT.takeDamage(20);
	Jerry.whoAmI();
}