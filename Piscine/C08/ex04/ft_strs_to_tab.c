/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:15:39 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/16 16:15:59 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

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

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (copy == 0)
		return (0);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	arr = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (arr == 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		arr[i].size = ft_strlen(av[i]);
		i++;
	}
	arr[ac] = (struct s_stock_str){0, 0, 0};
	return (arr);
}
