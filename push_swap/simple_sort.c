/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:03:24 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/25 12:03:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort2(t_stack *a)
{
	if (sort_check(a) == 0)
		swap(a, 1);
}

void	small_sort3(t_stack *a)
{
	int	min;
	int	max;

	min = find_min_max(a, -1);
	max = find_min_max(a, 1);
	if (sort_check(a) == 0)
	{
		if (a->array[0] == min && a->array[1] == max)
		{
			rev_shift(a, 1);
			swap(a, 0);
		}
		else
			swap(a, 0);
		if (a->array[2] == min)
			rev_shift(a, 1);
	}
	else
	{
		if (a->array[1] == min && a->array[0] == max)
			shift(a, 1);
		else if (a->array[2] == min && a->array[1] == max)
			rev_shift(a, 1);
	}
}

static void	last_handler(t_stack *a, t_stack *b, int min, int max)
{
	if (b->array[0] != min && b->array[0] != max)
	{
		while ((a->array[0] < b->array[0] || a->array[3]
				> b->array[0]) && b->size != 0)
			shift(a, 1);
	}
	else
	{
		if (a->array[0] == max)
			shift(a, 1);
		else if (b->array[0] == max)
			smart_shift(a, b, min, 1);
		else
			smart_shift(a, b, max, 1);
	}
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = find_min_max(a, -1);
	max = find_min_max(a, 1);
	push(a, b, -1);
	push(a, b, -1);
	small_sort3(a);
	if (b->array[0] > a->array[0] && b->array[0] < a->array[2]
		&& b->array[0] < a->array[1])
		shift(a, 1);
	else if (b->array[0] > a->array[0] && b->array[0] < a->array[2]
		&& b->array[0] > a->array[1])
		rev_shift(a, 1);
	push(b, a, 1);
	last_handler(a, b, min, max);
	push(b, a, 1);
	smart_shift(a, b, min, 1);
}
