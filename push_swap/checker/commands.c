/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:58:33 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/18 09:58:37 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	dshift(t_stack *a, t_stack *b, int rot)
{
	if (rot == 0)
	{
		shift(a);
		shift(b);
	}
	else if (rot == 1)
	{
		rev_shift(a);
		rev_shift(b);
	}
}

void	swap(t_stack *x)
{
	int	temp;

	temp = x->array[0];
	x->array[0] = x->array[1];
	x->array[1] = temp;
}

void	shift(t_stack *x)
{
	int	temp;
	int	i;

	i = 1;
	temp = x->array[0];
	while (i < x->size)
	{
		x->array[i - 1] = x->array[i];
		i++;
	}
	x->array[i - 1] = temp;
}

void	rev_shift(t_stack *x)
{
	int	temp;
	int	i;

	i = x->size - 1;
	temp = x->array[i];
	while (i > 0)
	{
		x->array[i] = x->array[i - 1];
		i--;
	}
	x->array[0] = temp;
}

void	push(t_stack *x, t_stack *y)
{
	int		i;

	i = y->size;
	while (i > 0)
	{
		y->array[i] = y->array[i - 1];
		i--;
	}
	y->array[0] = x->array[0];
	while (i < x->size)
	{
		x->array[i - 1] = x->array[i];
		i++;
	}
	x->size -= 1;
	y->size += 1;
}
