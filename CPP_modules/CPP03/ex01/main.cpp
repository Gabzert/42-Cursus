/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:15:46 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 11:33:14 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap CT("CT");
	ScavTrap Jerry("Jerry");

	CT.attack("Jerry");
	Jerry.takeDamage(10);
	Jerry.beRepaired(10);
	Jerry.attack("CT");
	CT.takeDamage(20);
	Jerry.guardGate();
}