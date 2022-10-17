/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:00:38 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/13 17:00:39 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	pointer_hex(unsigned long n, int *count)
{
	int		temp;
	char	*base;

	base = "0123456789abcdef";
	if (n > 0)
	{
		temp = n % 16;
		n = n / 16;
		pointer_hex(n, count);
		write(1, &base[temp], 1);
		*count += 1;
	}
}

int	ft_printmem(void *ptr, int *count)
{
	unsigned long	a;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return (1);
	}
	a = (unsigned long)ptr;
	write (1, "0x", 2);
	*count += 2;
	pointer_hex(a, count);
	return (1);
}
