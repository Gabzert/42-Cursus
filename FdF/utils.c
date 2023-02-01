/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:03:11 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/26 12:03:14 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	find_max(float a, float b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a >= b)
		return (a);
	else
		return (b);
}

char	*get_value(char *point)
{
	char	**temp;	

	if (ft_strchr(point, ',') == 0)
	{
		temp = ft_split(point, ',');
		return (temp[0]);
	}
	else
		return (point);
}

char	*get_color(char *point)
{
	char	**temp;	

	if (ft_strchr(point, ',') != 0)
	{
		temp = ft_split(point, ',');
		return (temp[1]);
	}
	else
		return ("0x00FFFFFF");
}

int	find_pos(char c, char *base, char *base2)
{
	int	i;

	i = 0;
	while (base[i] || base2[i])
	{
		if (c == base[i] || c == base2[i])
			return (c);
		i++;
	}
	return (-1);
}

int	hex_convert(char *color)
{
	int		c;
	int		i;
	char	*base;
	char	*base2;

	i = 0;
	c = 0;
	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	while (color[i])
	{
		c = c * 16 + find_pos(color[i], base, base2);
		i++;
	}
	return (c);
}
