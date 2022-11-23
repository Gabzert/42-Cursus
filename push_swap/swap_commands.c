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

static int	count(char **x)
{
	int	i; 

	i = 0;
	while (x[i])
		i++;
	return (i);
}

void	swap(int **a, int dir)
{
	int	*temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	if (dir > 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	shift(int **a, int dir)
{
	int	*temp;
	int		i;

	i = 1;
	temp = a[0];
	while (a[i])
	{
		a[i - 1] = a[i];
		i++;
	}
	a[i] = temp;
	if (dir > 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rev_shift(int **a, int dir)
{
	int	*temp;
	int		i;

	i = (sizeof(a) / sizeof(int));
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	if (dir > 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}


void	push(int **x, int **y, int dir)
{
	int		i;

	i = (sizeof(y) / sizeof(int));
	while (i < 0)
	{
		y[i] = y[i - 1];
		i--;
	}
	y[0] = x[0];
	while (x[i])
	{
		x[i - 1] = x[i];
		i++;
	}
	x[i] = 0;
	if (dir > 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
