/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:15:46 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 12:16:09 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2, int start)
{
	int	c;

	c = 0;
	while (s1[start] == s2[c] && (s1[start] != '\0' || s2[c] != '\0'))
	{
		start++;
		c++;
	}
	if (s2[c] == '\0')
		return (0);
	else
		return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		d;
	char	*first;

	d = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[d] != '\0')
	{
		if (str[d] == to_find[0])
		{	
			if (ft_strcmp(str, to_find, d) == 0)
			{
				first = &str[d];
				return (first);
			}
		}
		d++;
	}
	return (0);
}
