/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:03:10 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/02 10:03:16 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	input_check(int argc, char **argv)
{
	int	i;
	int	x;
	int	s;

	i = 1;
	s = 0;
	while (i <= argc)
	{
		x = i + 1;
		if (long_atoi(argv[i]) > 2147483647 || long_atoi(argv[i]) < -2147483648)
			return (1);
		if (argv[i][0] == '-')
			s = 1;
		if (ft_is_digit(argv[i] + s) == 0)
			return (1);
		while (x <= argc && ft_strncmp(argv[i], argv[x], 20) != 0)
			x++;
		if (x <= argc)
			return (1);
		i++;
	}
	return (0);
}


static int	sort_check(t_stack *a)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = find_min_max(a, -1);
	max = find_min_max(a, 1);
	while (i < a->size - 1)
	{
		if (a->array[i] > a->array[i + 1] && a->array[i + 1] != min)
			return (0);
		if (a->array[i + 1] == max && a->array[i] == min)
			return (0);
		if (a->array[0] < a->array[a->size - 1] && a->array[a->size - 1] != max)
			return (0);
		i++;
	}
	return (1);
}

int	cmd_check(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = "";
	if (cmd_handler(a, b, cmd) == 1)
		return (1);
	if (sort_check(a) == 0)
		return (1);
	return (0);
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
		if (cmd_check(&a, &b) == 1)
			write(2, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		free(a.array);
		free(b.array);
	}
	return (0);
}
