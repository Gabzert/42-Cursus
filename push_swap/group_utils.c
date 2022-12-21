/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:02:37 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/08 18:02:39 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*which_chunk(t_stack *a, int n)
{
	if (n == 1)
		return (a->chunk1);
	else if (n == 2)
		return (a->chunk2);
	else if (n == 3)
		return (a->chunk3);
	else
		return (a->chunk4);
}

int	*next_half(int *group, int n, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (n == group[i])
			break ;
	}
	if (i < size / 2)
		return (&group[0]);
	return (&group[size / 2]);
}

int	find_in_chunk(int *group, int n, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (n == group[i])
			break ;
	}
	if (i < size / 2)
		return (0);
	return (1);
}

int	group_empty(t_stack *b, int *group)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (group_check(group, b->array[i], b->c_size) == 1)
			return (0);
		i++;
	}
	return (1);
}
