/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:58:26 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/23 11:24:36 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base(){}

Base * generate(void)
{
	Base *ret;
	int random = rand() % 3;
	std::cout << random << std::endl;
	if (random == 0)
		ret = new A;
	else if (random == 1)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	identify(&p);
}

