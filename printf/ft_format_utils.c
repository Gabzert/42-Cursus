/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:36:58 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/17 11:37:01 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	is_flag(char c)
{
	char	*not_flag;

	not_flag = "dicsxXup%.";
	while (*not_flag)
	{
		if (*not_flag == c)
			return (0);
		not_flag++;
	}
	return (1);
}	

int	atoa(char *str)
{
	int	num;

	num = 0;
	while (is_flag(*str))
	{
		num = (num * 10) + ((*str) - '0');
		str++;
	}
	return (num);
}

int	parsecalc(char *str, t_format format)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		format->precision = atoa(str[i]);
	}
	else
	{
		format->width = atoa(str[i]);
		while (is_flag(str[i]))
			i++;
		if (str[i] == '.')
		{	
			i++;
			format->precision = atoa(str[i]);
		}
	}
	return (i);
}

void	parsing(t_format f, int *count)
{
	while (f->width-- > 0)
	{
		write(1, &f->parse, 1);
		*count += 1;
	}
}
