/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:26:57 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/04 16:26:59 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	set_ctr(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	border_check(char const *s1, char const *set,
		int side, size_t lenght)
{
	size_t	i;

	i = 0;
	if (side == -1)
	{
		i = lenght - 1;
		while (set_ctr(set, s1[i]))
			i--;
		return (i);
	}	
	while (set_ctr(set, s1[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lenght;
	char	*str;
	size_t	start;
	size_t	end;

	lenght = ft_strlen(s1);
	start = border_check(s1, set, 1, lenght);
	end = border_check(s1, set, -1, lenght);
	lenght = (end + 1) - start;
	str = (char *)malloc((lenght + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1 + start, lenght);
	str[lenght] = '\0';
	return (str);
}
