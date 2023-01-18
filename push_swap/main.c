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

static int	input_check(int argc, char **argv)
{
	int		i;
	int		x;

	i = 1;
	while (i <= argc)
	{
		x = i + 1;
		if (long_atoi(argv[i]) > 2147483647 || long_atoi(argv[i]) < -2147483648)
			return (1);
		if (ft_is_digit(argv[i]) == 0)
			return (1);
		while (x <= argc && ft_strncmp(argv[i], argv[x], 20) != 0)
			x++;
		if (x <= argc)
			return (1);
		i++;
	}
	return (0);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		small_sort2(a);
	else if (a->size == 3)
		small_sort3(a);
	else
		small_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = -1;
	argc -= 1;
	if (input_check(argc, argv) == 1)
		write(2, "Error\n", 6);
	else
	{
		a.array = ft_calloc(argc, sizeof(int *));
		a.size = argc;
		b.array = ft_calloc(a.size, sizeof(int *));
		b.size = 0;
		while (++i < argc)
			a.array[i] = ft_atoi(argv[i + 1]);
		if (sort_check(&a) == 1)
			smart_shift(&a, &b, find_min_max(&a, -1), 1);
		else if (argc < 6)
			simple_sort(&a, &b);
		else
			sort(&a, &b);
	}
	return (0);
}
