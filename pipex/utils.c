/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:32:37 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/12 11:32:42 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	path = env[i];
	path += 5;
	return (path);
}

char	*find_cmd(char *cmd, char **env)
{
	char	**path_list;
	char	*command;
	char	*tmp;
	int	i;

	i = 0;
	path_list = ft_split(find_path(env), ':');
	while (path_list[i])
	{
		tmp = ft_strjoin(path_list[i], "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		free(tmp);
		i++;
	}
	while(--i >= 0)
		free(path_list[i]);
	free(path_list);
	write(2, "command not found : ", 20);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	return (NULL);
}

void	free_child(char **input, t_pipex *pipe)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
	free_pipes(pipe->fd, pipe->fd_count - 1);
	exit(1);
}

void	take_input(char *eof, int *file)
{
	char	*str;
	int		len;
	int		fd;

	len = ft_strlen(eof);
	fd = open(".here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
	while (1)
	{
		write(1, "here_doc>", 9);
		str = get_next_line(0);
		if (ft_strncmp(str, eof, len) == 0)
			break ;
		write(fd, str, ft_strlen(str));
	}
	close(fd);
	*file = open(".here_doc", O_RDONLY);
}

void	pipex_init(t_pipex *p, char **argv, int argc)
{
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		p->here_doc = 0;
	else
		p->here_doc = 1;
	if ((p->here_doc == 0 && argc < 5) || (p->here_doc == 1 && argc < 6))
	{
		write(1, "wrong number of arguments \n", 27);
		exit(1);
	}
	p->i = 0;
	p->pidn = -1;
	p->fd = create_pipe(argc, argv, p);
}
