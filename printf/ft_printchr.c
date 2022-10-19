/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:22:48 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/13 14:22:49 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printchr(int c, int *count, t_format format)
{
	ft_formatter(format);
	if (format->width > 0 && format->minus == 1)
	{
		ft_putchar_fd(c, 1);
		*count += 1;
		parsing(format, count);
	}
	else
	{
		parsing(format, count);
		ft_putchar_fd(c, 1);
		*count += 1;
	}
	return (1);
}
