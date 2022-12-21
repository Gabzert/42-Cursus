/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:58:33 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/18 09:58:37 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dshift(t_stack *a, t_stack *b, int rot)
{
	if (rot == 0)
	{
		shift(a, 2);
		shift(b, 2);
		ft_printf("rr\n");
	}
	else if (rot == 1)
	{
		rev_shift(a, 2);
		rev_shift(b, 2);
		ft_printf("rrr\n");
	}
}

void	swap(t_stack *x, int side)
{
	int	temp;

	temp = x->array[0];
	x->array[0] = x->array[1];
	x->array[1] = temp;
	if (side == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	shift(t_stack *x, int side)
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
	if (side == 1)
		ft_printf("ra\n");
	else if (side == 0)
		ft_printf("rb\n");
}

void	rev_shift(t_stack *x, int side)
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
	if (side == 1)
		ft_printf("rra\n");
	else if (side == 0)
		ft_printf("rrb\n");
}

void	push(t_stack *x, t_stack *y, int side)
{
	int		i;

	i = y->size;
	while (i > 0)
	{
		y->array[i] = y->array[i - 1];
		i--;
	}
	y->array[0] = x->array[0];
	i = 1;
	while (i < x->size)
	{
		x->array[i - 1] = x->array[i];
		i++;
	}
	x->size -= 1;
	y->size += 1;
	if (side > 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
