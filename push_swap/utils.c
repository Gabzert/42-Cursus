/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:13:05 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/24 14:13:07 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_max(t_stack *a, int swap)
{
	int	i;
	int	n;

	i = 0;
	n = a->array[0];
	while (i < a->size)
	{
		if (swap > 0)
		{
			if (a->array[i] > n)
				n = a->array[i];
		}
		else
		{
			if (a->array[i] < n)
				n = a->array[i];
		}
		i++;
	}
	return (n);
}

int	find_first(t_stack *a, int c_max, int c_min, int side)
{
	int	i;

	if (side == 0)
	{
		i = 0;
		while (i < a->size)
		{	
			if (a->array[i] <= c_max && a->array[i] >= c_min)
				return (i);
			i++;
		}
	}
	else
	{
		i = a->size - 1;
		while (i >= 0)
		{
			if (a->array[i] <= c_max && a->array[i] >= c_min)
				return (a->size - i - 1);
			i--;
		}	
	}
	return (-1);
}

int	input_check(int argc, char **argv)
{
	int		i;
	int		x;

	i = 1;
	while (i < argc)
	{
		x = i + 1;
		if (ft_is_digit(argv[i]) == 0)
			return (1);
		while (ft_strncmp(argv[i], argv[x], 20) != 0 && x < argc)
			x++;
		if (x < argc - 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_digit(char *str)
{
	int	c;
	int	controllo;

	controllo = 1;
	c = 0;
	while (str[c] != '\0' )
	{
		if ((str[c] > '9' && str[c] < '0'))
		{
			controllo = 0;
			break ;
		}
		c++;
	}
	return (controllo);
}
