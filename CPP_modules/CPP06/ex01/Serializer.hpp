/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:21 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/21 17:12:38 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
private:
	Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();
};
