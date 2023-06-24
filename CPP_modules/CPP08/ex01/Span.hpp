/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:32:09 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/23 11:15:20 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _array;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	Span &operator=(const Span &a);
	~Span();

	unsigned int getSize();
	

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
};
