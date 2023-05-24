/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:54:26 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/24 10:20:48 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
    ScavTrap(std::string name);
	ScavTrap(const ScavTrap &toCopy);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();

	void guardGate();
};

#endif
