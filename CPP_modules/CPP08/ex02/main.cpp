/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:32:45 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/23 14:19:13 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	//[...]

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int i = 0;
	while (it != ite)
	{
		
		std::cout << "element " << i << ":" << *it << std::endl;
		++it;
		i++;
	}

	std::stack<int> s(mstack);
	
// test list

    MutantStack<int> mutantStack;
    for (int i = 1; i <= 5; ++i)
        mutantStack.push(i);

    std::cout << "Using MutantStack: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::list<int> myList;
    for (int i = 1; i <= 5; ++i)
        myList.push_back(i);

    std::cout << "Using std::list: ";
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;



	return 0;
}
