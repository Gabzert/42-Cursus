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

int	ft_check_flags(char *ptr, t_format format;)
{
	int	i;

	while (is_flag(ptr[i]) || (ptr[i] <= '9' && ptr[i] >= '0'))
	{
		if (ptr[i] == '0')
			format->zero = 1;
		else if (ptr[i] == ' ')
			format->space = 1;
		else if (ptr[i] == '-')
			format->minus = 1;
		else if (ptr[i] == '+')
			format->plus = 1;
		else if (ptr[i] == '#')
			format->hash = 1;
		i++;
	}
	if (ptr[i] == '.' || (ptr[i] <= '9' && ptr[i] >= '0'))
		i += parsecalc(&ptr[i], format);
	return (i);
}

int	ft_check_specifier(char c, va_list ptr, int *count, t_format format;)
{
	format->spec = c;
	if (c == 'd' || c == 'i')
		return (ft_printnum(va_arg(ptr, int), count, format));
	else if (c == 'c')
		return (ft_printchr(va_arg(ptr, int), count, format));
	else if (c == 's')
		return (ft_printstr(va_arg(ptr, char *), count, format));
	else if (c == 'x' || c == 'X' || c == 'u')
		return (ft_printhex(va_arg(ptr, unsigned int), c, count, format));
	else if (c == 'p')
		return (ft_printmem(va_arg(ptr, void *), count, format));
	else if (c == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_format	format;
	int			i;
	int			count;
	va_list		ptr;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += ft_check_flags(&((char *)str)[i], &count, format);
			i += ft_check_specifier(str[i + 1], ptr, &count, format);
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
