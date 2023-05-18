/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:02:23 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/17 12:01:00 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "Materia.hpp"

class Ice : public AMateria
{	
	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &a);
		~Ice();

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
