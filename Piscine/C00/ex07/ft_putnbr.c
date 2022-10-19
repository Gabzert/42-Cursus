/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:00:44 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/05 19:00:50 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(char arr[], int n)
{
	int	temp;
	int	counter;

	counter = 0;
	while (n != 0)
	{
		temp = n % 10;
		n = n / 10;
		arr[counter] = temp + '0' ;
		counter ++;
	}
	counter --;
	while (counter >= 0)
	{	
		if (arr[counter] != ' ')
		{
			write (1, &arr[counter], 1);
		}
		counter --;
	}
}

void	ft_putnbr(int i)
{
	char	a[10];

	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (i != 0)
		{
			if (i < 0)
			{
				write (1, "-", 1);
				i = i * -1;
			}
			print(a, i);
		}
		else
		{
			write (1, "0", 1);
		}
	}
}
