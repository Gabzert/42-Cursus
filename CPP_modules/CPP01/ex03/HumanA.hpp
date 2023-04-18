/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:06:44 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/15 16:34:22 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon *weapon;
	std::string name;
public:

	HumanA(std::string name, Weapon &found);
	~HumanA();
	void attack();
};
