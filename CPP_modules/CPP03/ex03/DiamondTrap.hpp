/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:58:27 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/24 10:20:20 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string Name;

public:
	DiamondTrap();
    DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &toCopy);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();

	using ScavTrap::attack;
	void whoAmI();
};

#endif
