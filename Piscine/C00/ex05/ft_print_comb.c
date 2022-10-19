/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:32:28 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/07 09:32:36 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(char x, char y, char z)
{
	if (x != y && y != z && z != x)
	{
		if (y < z && x < y)
		{
			write(1, &x, 1);
			write(1, &y, 1);
			write(1, &z, 1);
			if (x != '7' || y != '8')
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}			
		}
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				print(a, b, c);
				c++;
			}
			c = '0';
			b++;
		}
		b = '0';
		a++;
	}
}
/*
void main()
{
	ft_print_comb();
}
*/
