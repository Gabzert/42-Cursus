/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:58:24 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/18 09:58:29 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(t_stack *a, t_stack *b)
{
	int	max_b;
	int	max_a;

	while (b->size != 0)
	{
		max_b = find_min_max(b, 1);
		smart_shift(b, a, max_b, 0);
		smart_shift(a, b, max_a, 1);
		if (b->array[0] == max_b && b->size != 0)
			push(b, a, 1);
		max_b = find_min_max(b, 1);
		while (a->array[a->size - 1] > max_b && a->array[a->size - 1]
			!= find_min_max(a, 1))
			rev_shift(a, 1);
		max_a = a->array[0];
	}
	if (sort_check(a) == 1)
		smart_shift(a, b, find_min_max(a, -1), 1);
	free(a->array);
	free(a->chunk1);
	free(a->chunk2);
	free(a->chunk3);
	free(a->chunk4);
	free(b->array);
}

void	sort(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = 1;
	if (groups_init(a) == 0)
		return ;
	groups_fill(a);
	while (a->size != 0)
	{
		while (group_empty(a, which_chunk(a, chunk), chunk) == 0)
		{
			while (which_group(a, a->array[0]) == chunk && a->size != 0)
			{
				push(a, b, -1);
				if (find_in_chunk(which_chunk(a,
							which_group(a, b->array[0])),
						b->array[0], a->c_size) == 0)
					shift(b, 0);
			}
			shift(a, 1);
		}
		chunk++;
	}
	merge(a, b);
}

int	sort_check(t_stack *a)
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
		if (a->array[0] < a->array[a->size - 1] && (a->array[a->size - 1] != max
				|| a->array[0] != min))
			return (0);
		i++;
	}
	return (1);
}
