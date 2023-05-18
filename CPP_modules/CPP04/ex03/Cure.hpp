/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:21:21 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/17 14:22:03 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "Materia.hpp"

class Cure : public AMateria
{	
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &a);
		~Cure();

		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
