/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:48:58 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/07 09:49:47 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	print(int a, int x)
{
	char	arr[4];

	arr[0] = a / 10 + '0';
	arr[1] = a % 10 + '0';
	arr[2] = x / 10 + '0';
	arr[3] = x % 10 + '0';
	if (x != a)
	{
		if (x >= a)
		{
			write(1, &arr[0], 1);
			write(1, &arr[1], 1);
			write(1, " ", 1);
			write(1, &arr[2], 1);
			write(1, &arr[3], 1);
			if (a != 98 || x != 99)
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}			
		}
	}
}

void	var(int arr[])
{
	arr[0] = 0;
	arr[1] = 0;
}

void	ft_print_comb2(void)
{
	int	arr[2];

	var(arr);
	while (arr[0] <= 98)
	{
		while (arr[1] <= 99)
		{
			print (arr[0], arr[1]);
			arr[1]++;
		}
		arr[0]++;
		arr[1] = 0;
	}
}
/*
void main()
{
	ft_print_comb();
}
*/
