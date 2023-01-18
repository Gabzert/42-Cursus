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

void	close_pipes(int **fd)
{
	int	i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][1]);
		close(fd[i][0]);
		i++;
	}
}

void	free_pipes(int **fd)
{
	int	i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][1]);
		close(fd[i][0]);
		free(fd[i]);
		i++;
	}
	free(fd);
}

int	**create_pipe(int argc, char **argv)
{
	int	i;
	int	**fd;
	int	cmd_number;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		cmd_number = argc - 4;
	else
		cmd_number = argc - 3;
	fd = (int **)malloc((cmd_number - 1) * sizeof(int *));
	while (i < cmd_number)
	{
		fd[i] = (int *)malloc(2 * sizeof(int));
		if (pipe(fd[i]) == -1)
		{
			free_pipes(fd);
			return (NULL);
		}
		i++;
	}
	return (fd);
}
