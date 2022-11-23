/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:58:24 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/18 09:58:29 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int **a, int num, int avg)
{
	int		i;
	int	**b;

	i = 0;
	b = ft_calloc(num, sizeof(int **));
	while (i < num)
	{
		if (a[0] > avg)
			push(a, b, -1);
		shift(a, 1)
		i++;
	}
	
}	

int	sort_check(int **a, int size)
{
	int	n;
	int	i;
	int	max;
	int	min;

	i = 1;
	n = 0;
	// find max;
	// find min;
	while (n < size)
	{
		if (a[i] > a[i + 1] && a[i] != max && a[i + 1] != min)
			return (0);
		n++;
	}
	return (1);
}



