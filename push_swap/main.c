/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:40:13 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/14 14:40:15 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_average(int argc, int **argv)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (i < argc)
	{
		n += a[i];
		i++;
	}
	n /= argc;
	return (n);
}
		
int	input_check(int argc, char **argv)
{
	int		i;
	int		j;
	int		x;

	j = 0;
	i = 0;
	while (i <= argc)
	{
		x = 0;
		while (ft_is_digit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0')
			return (1);
		while (!ft_strcmp(argv[i], argv[x]))
			x++;
		if (x < argc)
			return (1);
		i++;
	}
	return (0);
}

int	simple_sort(int num, char **a)
{
		
}
int	main(int argc, char **argv)
{
	int	**a;
	int	c;
	int	i;

	i = 0;
	if (input_check(argc, argv) == 1)
		write(2, "Error\n", 6);
	else if (argc < 6)
		simple_sort(argc, argv);
	else 
	{
		while (i < argc)
		{
			a[i] = ft_atoi(argv[i]);
			i++;
		}
		c = find_average(argc, a);	
		sort(a, argc, c);
	}
	return (0);
}
