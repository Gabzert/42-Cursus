/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:40:32 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/22 12:05:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
// Sample function: print
void print(int &value)
{
    std::cout << value << " ";
}

// Sample function: square
void square(int& value)
{
    value *= value;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Array: ";
    iter(numbers, size, print);
    std::cout << std::endl;

    std::cout << "Squared Array: ";
    iter(numbers, size, square);
    iter(numbers, size, print);
    std::cout << std::endl;

	return 0;
}
