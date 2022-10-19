/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:36:41 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/07 09:38:18 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	check(char array[], int d)
{
	int		pos;
	char	check;

	check = 'G';
	pos = 0;
	while (pos < d)
	{
		if (array[pos + 1] < array[pos])
		{
			check = 'G';
		}
		else
		{
			check = 'B';
			break ;
		}
		pos++;
	}
	return (check);
}

void	print(char array[], int s)
{
	int	temp;

	temp = s - 1;
	if (check(array, s) == 'G')
	{
		while (temp >= 0)
		{
			write(1, &array[temp], 1);
			temp --;
		}
		if (array[s - 1] != ('9' - (s - 1)))
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	cycle(char list[], int g)
{
	int	op;

	op = 0;
	while (op < g)
	{
		while (list[op] <= '9')
		{
			print(list, g);
			list[op]++;
			if (list[op] > list[op - 1])
			{
				if (op > 0)
				{
					op--;
				}
			}
		}
		list[op] = '0';
		op++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];
	int		temp;

	temp = n - 1;
	while (temp >= 0)
	{
		arr[temp] = '0';
		temp--;
	}
	cycle(arr, n);
}
