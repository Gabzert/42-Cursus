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

static void	ft_putunsigned(unsigned int n, int *count)
{
	char	c;

	if (n / 10)
		ft_putunsigned(n / 10, count);
	c = '0' + n % 10;
	write(1, &c, 1);
	*count += 1;
}

static void	convert(unsigned int n, char c, int *count)
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
		convert(n, c, count);
		if (format->width > 0 && format->minus == 1)
			parsing(format, count);
		write(1, &base[temp], 1);
		if (format->width > 0 && format->minus != 1)
			parsing(format, count);
		*count += 1;
	}
}

int	ft_printhex(unsigned int n, char c, int *count)
{
	ft_formatter(format);
	if (n == 0)
	{
		if (format->width > 0 && format->minus == 1)
			parsing(format, count);
		write(1, "0", 1);
		*count += 1;
		if (format->width > 0 && format->minus != 1)
			parsing(format, count);
		return (1);
	}
	if (c == 'x' || c == 'X')
	{
		convert(n, c, count);
	}
	else
	{
		if (format->width > 0 && format->minus == 1)
			parsing(format, count);
		ft_putunsigned(n, count);
		if (format->width > 0 && format->minus != 1)
			parsing(format, count);
	}
	return (1);
}
