/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:56:58 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/15 16:35:25 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string name);
	~HumanB();

	Weapon *getWeapon() const { return weapon; }
	void setWeapon(Weapon &weapon_) { weapon = &weapon_; }

	void attack();
};
