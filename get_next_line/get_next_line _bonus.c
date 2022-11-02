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

#include "get_next_line.h"

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
		sup = ft_realloc(*stat);
		*stat = ft_strjoin(sup, temp);
		free(sup);
		str = find_end(*stat, res);
		if (str != NULL)
		{
			sup = ft_realloc(*stat);
			*stat = strcut(sup);
			free(sup);
			return (str);
		}
	}
	return (NULL);
}

t_lines	find_in_list(t_lines *line, int fd);
{
	t_list	new;

	while (line)
	{
		if (line->fd == fd)
			return (line);
		line = line->next;
	}
	new.fd = fd;
	new.offset = malloc(sizeof(char *) * 1);
	new.offset[0] = '\0';
	line = new;
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	static t_lines	list;
	t_lines	line;

	if (fd == -1)
		return (NULL);
	line = find_in_list(&list, fd);	
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	str = read_line(fd, &line.offset, buffer);
	free(buffer);
	return (str);
}
