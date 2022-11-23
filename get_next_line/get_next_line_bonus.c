/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:48:09 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/26 15:48:13 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_end(char *str, int res)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (ft_substr(str, 0, i + 1));
		i++;
	}
	if (res == 0 && str[0] != '\0')
		return (ft_substr(str, 0, i));
	return (NULL);
}

char	*read_line(int fd, char **stat, char *temp)
{
	int		res;
	char	*str;
	char	*sup;

	res = 1;
	while (res != 0)
	{
		res = read(fd, temp, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		temp[res] = '\0';
		sup = *stat;
		*stat = ft_strjoin(sup, temp);
		free(sup);
		str = find_end(*stat, res);
		if (str != NULL)
		{
			sup = *stat;
			*stat = strcut(sup);
			return (str);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	static char	*offsets[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (offsets[fd] == NULL)
	{
		offsets[fd] = malloc(sizeof(char *) * 1);
		if (!offsets[fd])
			return (NULL);
		offsets[fd][0] = '\0';
	}
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	str = read_line(fd, &offsets[fd], buffer);
	if (str == NULL)
	{
		free(offsets[fd]);
		offsets[fd] = NULL;
	}
	free(buffer);
	return (str);
}
