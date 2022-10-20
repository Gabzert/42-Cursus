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

int	ft_printstr(char *str, int *count, t_format *f)
{
	char	*res;

	if (str == NULL)
	{
		res = malloc(7 * sizeof(char));
		res = "(null)";
		ft_printer(f, res, count);
		return (1);
	}
	res = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_strcpy(res, str);
	ft_printer(f, res, count);
	return (1);
}
