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

static void	merge(t_stack *a, t_stack *b, int max, int min)
{
	int		f_bottom;
	int		f_top;

	f_top = find_first(a, max, min, 0);
	f_bottom = find_first(a, max, min, -1);
	if (f_top > f_bottom)
		smart_shift(a, b, a->array[a->size - f_bottom - 1], 1);
	else
		smart_shift(a, b, a->array[f_top], 1);
	if (adjust_b(b, a->array[0]) == 1)
		fix_b(b, a, a->array[0]);
}

void	sort(t_stack *a, t_stack *b)
{
	int		c_min;
	int		c_max;

	c_min = find_min_max(a, -1);
	c_max = c_min + 10;
	while (a->size != 0)
	{
		while (find_first(a, c_max, c_min, 0) == -1)
		{
			c_min += 11;
			c_max = c_min + 10;
		}
		merge(a, b, c_max, c_min);
		push(a, b, -1);
	}
	smart_shift(b, a, find_min_max(b, 1), 0);
	while (b->size > 0)
		push(b, a, 1);
}	

int	sort_check(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = find_min_max(a, -1);
	while (i < a->size)
	{
		if (a->array[i] > a->array[i + 1] && a->array[i + 1] != min)
			return (0);
		i++;
	}
	return (1);
}	
