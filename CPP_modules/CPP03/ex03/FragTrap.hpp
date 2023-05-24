/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:39:02 by gabriele          #+#    #+#             */
/*   Updated: 2023/05/24 10:20:58 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap();
    FragTrap(std::string name);
	FragTrap(const FragTrap &toCopy);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap();

	void highFivesGuys(void);
};

#endif
