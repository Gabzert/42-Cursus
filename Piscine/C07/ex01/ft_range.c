/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:07:52 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/16 10:08:07 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	diff;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	diff = max - min;
	range = (int *)malloc(diff * sizeof(int));
	while (i < diff)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
