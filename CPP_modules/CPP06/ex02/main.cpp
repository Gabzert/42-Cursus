/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:22:23 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/23 11:31:00 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>

int main()
{
    std::srand((unsigned) std::time(NULL));
    
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << std::endl;

    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b ); std::cout << std::endl;

    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c ); std::cout << std::endl;

    std::cout << "d* = "; identify( d );
    std::cout << "d& = "; identify( *d ); std::cout << std::endl;


    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}
