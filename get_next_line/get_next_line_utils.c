/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:48:27 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/26 15:48:31 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_realloc(char *str)
{
	int		i;
	char	*supp;

	i = 0;
	supp = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i])
	{
		supp[i] = str[i];
		i++;
	}
	supp[i] = '\0';
	free(str);
	return (supp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		c;
	int		x;

	c = 0;
	x = 0;
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		new[c] = s1[x];
		c++;
		x++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		new[c] = s2[x];
		c++;
		x++;
	}
	new[c] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*sub;

	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(1 * sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	c = 0;
	while (((char *)s)[start] != '\0' && c < len)
	{
		sub[c] = ((char *)s)[start];
		c++;
		start++;
	}
	sub[c] = '\0';
	return (sub);
}

char	*strcut(char *str)
{
	char	*cut;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	cut = malloc(sizeof(char *) * (ft_strlen(&str[i]) + 1));
	while (str[i] != '\0')
	{
		cut[j] = str[i];
		i++;
		j++;
	}
	cut[j] = '\0';
	return (cut);
}
