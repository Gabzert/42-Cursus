/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:59:14 by gfantech          #+#    #+#             */
/*   Updated: 2023/07/03 10:58:47 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

template <typename Container>
int findInS(Container S, int pair)
{
	for (size_t i = 0; i < S.size(); i++)
	{
		if (S[i] == pair)
			return (i);
	}
	return (-1);
}


template <typename Container>
void binarySearch(Container S, Container &c, int paired[])
{
	for (size_t i = 0; i < c.size(); i++)
	{
	    int low = 0;
    	int high = findInS(S, paired[i]);

    	while (low <= high)
		{
        	int mid = low + (high - low) / 2;
			if (S[mid] < c[i])
				low = mid + 1;
			else
				high = mid - 1;
    	}
		S.insert(S.begin() + low, c[i]);
	}
	c.clear();
	c = S;
}

template <typename Container>
void invertSection(Container& container, size_t startIndex, size_t endIndex)
{
    while (startIndex < endIndex)
    {
        std::swap(container[startIndex], container[endIndex]);
        ++startIndex;
        --endIndex;
    }
}

template <typename Container>
void jackbSequence(Container &c, int paired[])
{
	unsigned int x = 0;
	unsigned int jacobsthalB = 0;
	unsigned int jacobsthalN = 2;
	for (size_t i = 0; i < c.size(); i++)
	{
		if (x == jacobsthalN )
		{
			invertSection(c, i - x, i);
			invertSection(paired, i - x, i);
			x = 0;
			int temp = jacobsthalN;
			jacobsthalN += (jacobsthalB * 2);
			jacobsthalB = temp;
		}
		else
			x++;
	}
}

template <typename Container>
Container makeS(Container &c)
{
	Container s;
	Container pend;
	s.push_back(c[0]);
    for (size_t i = 1; i <= c.size() - 1; i += 2)
	{
		s.push_back(c[i]);
		pend.push_back(c[i - 1]);
	}
	if (c.size() % 2 == 1)
		pend.push_back(c[c.size() - 1]);
	pend.erase(pend.begin());
	c.clear();
	c = pend;
	return (s);
}


template <typename Container>
void mergePairs(Container &c, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int i = 1; i < size; i += 2)
		{
			if (c[i] > c[i + 2])
			{
				std::iter_swap(c.begin() + i, c.begin() + i + 2);
				std::iter_swap(c.begin() + i - 1, c.begin() + i + 1);
			}
		}
	}
	
}

template <typename Container>
void orderPairs(Container &c, int last)
{
	for (int i = 0; i <= last; i += 2)
	{
		if (c[i] > c[i + 1])
        	std::iter_swap(c.begin() + i, c.begin() + i + 1);
    }
    mergePairs(c, last);
}


void sortVector(std::vector<int> &v)
{
	double timeS = get_time();
	if (v.size() % 2 == 0)
		orderPairs(v, v.size() - 1);
	else
		orderPairs(v, v.size() - 2);
	std::vector<int> S = makeS(v);
	int paired[v.size()];
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i + 2 > S.size() - 1)
			paired[i] = S[S.size() - 1];
		else
			paired[i] = S[i + 2];
	}
	jackbSequence(v, paired);
	binarySearch(S, v, paired);
	double timeF = get_time();
	std::cout << "After :" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements using <vectors> : " << timeF - timeS << " us" << std::endl;
}

void sortDeque(std::deque<int> &d)
{
	double timeS = get_time();
	if (d.size() % 2 == 0)
		orderPairs(d, d.size() - 1);
	else
		orderPairs(d, d.size() - 2);
	std::deque<int> S = makeS(d);
	int paired[d.size()];
	for (size_t i = 0; i < d.size(); i++) {paired[i] = S[i];}
	jackbSequence(d, paired);
	binarySearch(S, d, paired);
	double timeF = get_time();
	std::cout << "Time to process a range of " << d.size() << " elements using <deques> : " << timeF - timeS << " us" << std::endl;
}

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
	sortVector(vector);
	sortDeque(deque);
}
