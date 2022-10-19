/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:57:49 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/13 12:57:52 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnbr(int n, int *count)
{
	int		sign;
	char	c;

	sign = 1;

	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		sign = -1;
	}
	if (n / 10)
		ft_putnbr(n / 10 * sign, count);
	c = '0' + n % 10 * sign;
	write(1, &c, 1);
	*count += 1;

}

int	ft_printnum(int val, int *count)
{
	ft_formatter(format);
	if (val == 0)
	{
		if (format->width > 0 && format->minus == 1)
			parsing(format, count);
		write(1, "0", 1);
		*count += 1;
		if (format->width > 0 && format->minus != 1)
			parsing(format, count);
		return (1);
	}
	if (format->width > 0 && format->minus == 1)
		parsing(format, count);
	ft_putnbr(val, count);
	if (format->width > 0 && format->minus != 1)
		parsing(format, count);
	return (1);
}
