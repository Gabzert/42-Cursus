/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:35:09 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/18 14:35:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

	

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (src[c] != '\0' && c < n)
	{
		dest[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dest[c] = '\0';
		c++;
	}	
	return (dest);
}

int	add_string(char *str, char *start, int size)
{
	
	ft_strncpy(str, start, size);
	return(1)	
}

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return(1);
}
int	size_calc(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], sep) == 0)
			count++;
		i++;
	}
	return (count);	
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		c;
	char	**array;
	char	*inizio;
	char	*fine;
	
	c = 0;
	array = (char **)malloc(size_calc(str, charset) * sizeof(char *));
	if (array == 0)
		return(0);
	i = 0;
	inizio = str;
	fine = str;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset) == 0)
			fine = &str[i];
		if ((fine - inizio)> 1)
			c += add_string(array[c], inizio, (fine - inizio));
		inizio = fine;
		i++;
	}
	array[c] = 0;
	return (array);
}
