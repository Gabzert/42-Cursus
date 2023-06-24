/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:01:42 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/21 17:13:53 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main()
{
	Data *data = new Data;
	uintptr_t test;
	data->str = "string";
	data->num = 42;
	data->c = 'a';

	std::cout << "data: " << std::endl << data->str << std::endl << data->num << std::endl << data->c << std::endl;
	test = Serializer::serialize(data);
	data = Serializer::deserialize(test);

	std::cout << "after_data: " << std::endl << data->str << std::endl << data->num << std::endl << data->c << std::endl;
	delete data;

	return (0);
}

