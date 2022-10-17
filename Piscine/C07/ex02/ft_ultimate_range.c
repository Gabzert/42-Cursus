/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:30 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/16 10:15:37 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*numbers;
	int	diff;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	diff = max - min;
	numbers = (int *)malloc(diff * sizeof(int));
	if (numbers == 0)
	{
		*range = 0;
		return (-1);
	}
	while (i < diff)
	{
		numbers[i] = min + i;
		i++;
	}
	*range = numbers;
	return (i);
}
