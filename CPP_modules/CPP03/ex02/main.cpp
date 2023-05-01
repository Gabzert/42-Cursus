/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:15:46 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 11:53:07 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap CT("CT");
	FragTrap Jerry("Jerry");

	CT.attack("Jerry");
	Jerry.takeDamage(10);
	Jerry.beRepaired(10);
	Jerry.attack("CT");
	CT.takeDamage(20);
	Jerry.highFivesGuys();
}