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

void	fix_b(t_stack *b, t_stack *a, int num)
{
	int	min_b;
	int	max_b;
	int before_num;
	int i;

	max_b = find_min_max(b, 1);
	min_b = find_min_max(b, -1);
	i = 0;
	if (num < min_b || num > max_b)
		smart_shift(b, a, max_b, 0);
	else if (min_b < num < max_b)
	 {
		before_num = min_b;
		while(i < b->size)
		{
				if (num - b->array[i] < num - before_num && b->array[i] < num)
					before_num = b->array[i];
				i++;
		}
		smart_shift(b, a, before_num, 0);
	 }
}

int	find_pos(t_stack *x, int num)
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

int	adjust_b(t_stack *b, int num)
{
	int	min_b;
	int	max_b;	

	max_b = find_min_max(b, 1);
	min_b = find_min_max(b, -1);
	if (num < min_b || num > max_b)
	{
		if (b->array[0] != find_min_max(b, 1))
			return (1);
	}
	else if (min_b < num < max_b)
	{
		if (b->array[0] > num || b->array[b->size] < num)
			return (1);
	}
	return (0);
}

void	smart_shift(t_stack *x, t_stack *y, int num, int side)
{
	int	i;
	int	center;

	i = find_pos(x, num);
	center = (x->size / 2);
	while (x->array[0] != num)
	{
		if (i < center)
		{
			if (adjust_b(y, num) == 1 && side == 1)
				dshift(x, y, 0);
			else
				shift(x, side);
		}
		else
		{
			if (adjust_b(y, num) == 1 && side == 1)
				dshift(x, y, 1);
			else
				rev_shift(x, side);
		}
	}
}
