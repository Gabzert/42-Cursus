/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:34:27 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/20 13:34:29 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printer(t_format *f, char *str, int *count)
{
	int		diff;

	diff = 0;
	if (ft_strlen(str) < f->width)
		diff = f->width - ft_strlen(s);
	*count += ft_strlen(str);
	*count += diff;
	if (f->minus != 1)
	{
		while(diff > 0)
		{
			write(1, &f->parse, 1);
			diff--; 
		}
	}
	write(1, str, ft_strlen(str);
	if (f->minus == 1)
	{
		while(diff > 0)
		{
			write(1, &f->parse, 1);
			diff--; 
		}
	}
	free(str);
}
