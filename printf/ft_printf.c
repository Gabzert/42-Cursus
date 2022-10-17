/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:15:26 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/12 12:15:27 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*
int	ft_check_flags(char *ptr)
{

}
*/
int	ft_check_specifier(char c, va_list ptr, int *count)
{
	if (c == 'd' || c == 'i')
		return (ft_printnum(va_arg(ptr, int), count));
	else if (c == 'c')
		return (ft_printchr(va_arg(ptr, int), count));
	else if (c == 's')
		return (ft_printstr(va_arg(ptr, char *), count));
	else if (c == 'x' || c == 'X' || c == 'u')
		return (ft_printhex(va_arg(ptr, unsigned int), c, count));
	else if (c == 'p')
		return (ft_printmem(va_arg(ptr, void *), count));
	else if (c == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			//i += ft_check_flags(&((char *)str)[i]);
			i += ft_check_specifier(str[i + 1], ptr, &count);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(ptr);
	return (count);
}
