/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:25:24 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/13 14:25:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putstr(char *s, int *count)
{
	write(1, s, ft_strlen(s));
	*count += ft_strlen(s);
}

int	ft_printstr(char *str, int *count)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
		return (1);
	}
	ft_putstr(str, count);
	return (1);
}
