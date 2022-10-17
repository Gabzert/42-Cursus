/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:46:46 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/16 10:47:01 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (dest[d] != '\0')
	{
		d++;
	}
	while (src[c] != '\0')
	{
		dest[d] = src[c];
		c++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

int	calcolo_malloc(int size, char **strs, char *sep)
{
	int	c;
	int	total_lenght;

	c = 0;
	total_lenght = 0;
	while (c < size)
	{
		total_lenght += ft_strlen(strs[c]);
		total_lenght += ft_strlen(sep);
		c++;
	}
	return (total_lenght);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;

	i = 0;
	if (size == 0)
	{
		return ((char *)malloc(sizeof(char)));
	}
	res = (char *)malloc(calcolo_malloc(size, strs, sep) * sizeof(char));
	res[0] = '\0';
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		ft_strcat(res, sep);
		i++;
	}
	return (res);
}
