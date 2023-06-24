/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:06:49 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/22 15:36:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        Array<int> empty;
        std::cout << "Empty Array size: " << empty.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Int Array size: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i + 1;
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        Array<int> copied(intArray);
        copied[0] = 100;

        Array<int> assigned;
        assigned = intArray;
        assigned[1] = 200;

        std::cout << "Copied Array size: " << copied.size() << std::endl;
        std::cout << "Assigned Array size: " << assigned.size() << std::endl;
        std::cout << "Original Array size: " << intArray.size() << std::endl;

		intArray[345];
    } catch (const std::exception& e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
