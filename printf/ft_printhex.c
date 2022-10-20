/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:48:10 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/13 14:48:12 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_count_num(int n, int radix)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / radix;
		len++;
	}
}

static void	ft_putunsigned(unsigned int n, int i)
{
	char	c;

	if (n / 10)
		ft_putunsigned(n / 10, i + 1);
	c = '0' + n % 10;
	res[i] = c;
}

static void	convert(unsigned int n, char c, int i, char *res)
{
	int		temp;
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 0)
	{
		temp = n % 16;
		n = n / 16;
		convert(n, c, i + 1);
		res[i] = &base[temp];
	}
}

int	ft_printhex(unsigned int n, char c, int *count)
{
	char	*res;

	if (n == 0)
	{
		res = malloc(2 * sizeof(char));
		res[0] = c;
		res[1] = '\0';
		ft_printer(f, res, count);
		return (1);
	}
	if (c == 'x' || c == 'X')
	{
		res = malloc((ft_count_num(n, 16) + 1) * sizeof(char));
		convert(n, c, 0, res);
		res[ft_count_num(n, 16) + 1] = '\0';
	}
	else
	{
		res = malloc((ft_count_num(n, 10) + 1) * sizeof(char));
		ft_putunsigned(n, 0);
		res[ft_count_num(n, 10) + 1] = '\0';
	}
	return (1);
}
