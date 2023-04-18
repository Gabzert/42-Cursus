/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:53:26 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/15 16:34:24 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	
	std::string getType() const
	{
		return this->type;
	}

	void setType(std::string type)
	{
		this->type = type;
	}
	
};
#endif
