/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:36:17 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/30 10:36:21 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_shift(t_stack *a, t_stack *b)
{
	while (b->array[0] < a->array[0] && a->size != 0)
	{
		if (b->array[0] > a->array[a->size - 1] || a->array[a->size - 1]
			== find_min_max(a, 1))
		{
			push(b, a, 1);
			if (a->array[a->size - 1] < a->array[0] || (a->array[a->size - 1]
					== find_min_max(a, 1) && b->array[0] > a->array[0]))
				shift(a, 1);
		}
		else
			break ;
	}
}

static int	find_pos(t_stack *x, int num)
{
	int	i;

	i = 0;
	while (i < x->size)
	{
		if (x->array[i] == num)
			break ;
		i++;
	}
	return (i);
}

static int	find_num(t_stack *x, int num)
{
	int	i;

	i = 0;
	while (i < x->size)
	{
		if (x->array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	smart_shift(t_stack *x, t_stack *y, int num, int side)
{
	int	i;
	int	center;

	i = find_pos(x, num);
	if (i >= x->size)
		return ;
	center = (x->size / 2);
	while (x->array[0] != num)
	{
		if (side == 0)
			optimize_shift(y, x);
		if (x->array[0] == num || find_num(x, num) == 0)
			break ;
		if (i <= center)
			shift(x, side);
		else
			rev_shift(x, side);
	}
}
