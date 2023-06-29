/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:59:14 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/29 15:15:13 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void orderPairs(std::vector<int> &v, int start, int end)
{
	if (end - start != 2)
	{
		int half = (start + end) / 2;
		orderPairs(v, start, half);
		orderPairs(v, half + 1, end);
		mergePairs();
	}
	else if (v[start] > v[end])
		iter_swap(v.begin() + start, v.begin() + end);
}

void mergePairs(std::vector<int> &v, int size, std::vector<int>::iterator last)
{
    if (size < 0)
        v[0] = *last;
    else if (*last >= v[size])
	{
        if (size == v.size() - 1)
            v.push_back(*last);
        else
            v[size + 1] = *last;
    }
    else
	{
        if (size == v.size() - 1)
            v.push_back(v[size]);
        else
		{
            v[size + 1] = v[size];
            v.insert(v.begin() + size, *last);
        }
    }
}

// build utility functions for recursive insertion sort by highest value in pair
def insert(element, A, n):
  if n < 0:
    A[0] = element
  elif element[1] >= A[n][1]:
    if n == len(A)-1:
      A.append(element)
    else:
      A[n+1] = element
  else:
    if n == len(A)-1:
      A.append(A[n])
    else:
      A[n+1] = A[n]
      insert(element, A, n-1)

// entry function to recusrively sort pairs by their higher value
def insertion_sort_pairs(A, n):
  if n < 1:
    return A
  else:
    insertion_sort_pairs(A, n-1)
    insert(A[n], A, n-1)


void PmergeMe(int ac, char **argv)
{
	std::vector<int> vector;
	std::deque<int> deque;

	for (int i = 1; i < ac; i++)
	{
		vector.push_back(atoi(argv[i]));
		deque.push_back(atoi(argv[i]));
	}
	std::cout << "Before :" << std::endl;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	
}
