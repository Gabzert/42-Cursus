/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:01:26 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/10 11:02:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	bool	out;
	int		i;

	i = 0;
	out = false;
	while (!out)
	{
		i = 0;
		out = true;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				out = false;
			}
			i++;
		}
	}
}
