/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:54:26 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/01 11:29:40 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
    ScavTrap(std::string name);
	ScavTrap(const ScavTrap &toCopy);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();

	void guardGate();
};

#endif