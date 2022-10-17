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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	final_length(char **strings, int size, int sep_length)
{
	int	final_length;
	int	i;

	final_length = 0;
	i = 0;
	while (i < size)
	{
		final_length += ft_strlen(strings[i]);
		final_length += sep_length;
		i++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*read_head;
	char	*string;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	string = (char *)malloc((final_length(strs, size, ft_strlen(sep)) + 1)
			* sizeof(char));
	if (!string)
		return (0);
	read_head = string;
	i = 0;
	while (i < size)
	{
		ft_strcpy(read_head, strs[i]);
		read_head += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(read_head, sep);
			read_head += ft_strlen(sep);
		}
		i++;
	}
	*read_head = '\0';
	return (string);
}
