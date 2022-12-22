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

int	find_the_min(t_stack *a, int c_size)
{
	int	i;
	int	j;
	int	c;
	int	num;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		c = 0;
		while (j < a->size)
		{
			if (a->array[i] > a->array[j])
				c++;
			j++;
		}
		if (c == c_size - 1)
			num = a->array[i];
		i++;
	}
	return (num);
}

int	find_first(t_stack *a, int c_max, int side)
{
	int	i;

	if (side == 0)
	{
		i = 0;
		while (i < a->size)
		{	
			if (a->array[i] <= c_max)
				return (i);
			i++;
		}
	}
	else
	{
		i = a->size - 1;
		while (i >= 0)
		{
			if (a->array[i] <= c_max)
				return (a->size - i - 1);
			i--;
		}	
	}
	return (-1);
}

long	long_atoi(char *str)
{
	long int	num;
	int			neg;

	num = 0;
	neg = 1;
	while (*str == 32 || *str == 9 || *str == '\r' || *str == '\v'
		|| *str == '\n' || *str == '\f')
	{
		str++;
	}
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		num = (num * 10) + ((*str) - '0');
		str++;
	}
	return (num * neg);
}

int	ft_is_digit(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0' )
	{
		if (str[c] > '9' || str[c] < '0')
			return (0);
		c++;
	}
	return (1);
}
