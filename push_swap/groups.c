/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:57:11 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/07 10:57:13 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	group_check(int *group, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == group[i])
			return (1);
		i++;
	}
	return (0);
}

int	groups_init(t_stack *a)
{
	a->c_size = a->size / 4;
	a->c_offset = a->size % 4;
	a->chunk1 = malloc(a->c_size * sizeof (int *));
	a->chunk2 = malloc(a->c_size * sizeof (int *));
	a->chunk3 = malloc(a->c_size * sizeof (int *));
	a->chunk4 = malloc((a->c_size + a->c_offset) * sizeof (int *));
	if (!a->chunk1 || !a->chunk2 || !a->chunk3 || !a->chunk4)
		return (0);
	return (1);
}

void	groups_fill(t_stack *a)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < a->size)
	{
		j = -1;
		c = 0;
		while (++j < a->size)
		{
			if (a->array[i] > a->array[j])
				c++;
		}
		if (c < (a->c_size))
			a->chunk1[c] = a->array[i];
		else if (c < (a->c_size * 2))
			a->chunk2[c - a->c_size] = a->array[i];
		else if (c < 3 * a->c_size)
			a->chunk3[c - (a->c_size * 2)] = a->array[i];
		else
			a->chunk4[c - (3 * a->c_size)] = a->array[i];
		c++;
		i++;
	}
}

int	which_group(t_stack *a, int n)
{
	if (group_check(a->chunk1, n, a->c_size) == 1)
		return (1);
	else if (group_check(a->chunk2, n, a->c_size) == 1)
		return (2);
	else if (group_check(a->chunk3, n, a->c_size) == 1)
		return (3);
	else if (group_check(a->chunk4, n, a->c_size + a->c_offset) == 1)
		return (4);
	return (0);
}
