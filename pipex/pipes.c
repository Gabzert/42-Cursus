/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:14:43 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/16 14:14:49 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int **fd, int i)
{
	while (i >= 0)
	{
		close(fd[i][1]);
		close(fd[i][0]);
		i--;
	}
}

void	free_pipes(int **fd, int i)
{
	while (i >= 0)
	{
		close(fd[i][1]);
		close(fd[i][0]);
		free(fd[i]);
		i--;
	}
	free(fd);
}

int	**create_pipe(int argc, char **argv, t_pipex *p)
{
	int	i;
	int	**fd;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		p->fd_count = argc - 5;
	else
		p->fd_count = argc - 4;
	fd = (int **)malloc((p->fd_count) * sizeof(int *));
	while (i < p->fd_count)
	{
		fd[i] = (int *)malloc(2 * sizeof(int));
		if (pipe(fd[i]) == -1)
		{
			free_pipes(fd, i);
			return (NULL);
		}
		i++;
	}
	return (fd);
}
