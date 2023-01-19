/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:07:44 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/21 11:07:46 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_child_first(t_pipex pipe, char **argv, char **env)
{
	int		file;
	char	**input;
	char	*cmd;

	input = ft_split(argv[2 + pipe.here_doc], ' ');
	if (pipe.here_doc == 0)
		file = open(argv[1], O_RDWR);
	else
		take_input(argv[2], &file);
	if (file == -1)
	{
		perror(argv[1]);
		free_child(input, &pipe);
	}
	cmd = find_cmd(input[0], env);
	if (cmd == NULL)
		free_child(input, &pipe);
	dup2(file, 0);
	dup2(pipe.fd[pipe.i][1], 1);
	close_pipes(pipe.fd, pipe.fd_count - 1);
	if (execve(cmd, input, env) == -1)
	{
		perror("execution failed");
		free_child(input, &pipe);
	}
}

void	run_child_middle(t_pipex pipe, char **input, char **env)
{
	char	*cmd;

	cmd = find_cmd(input[0], env);
	if (cmd == NULL)
		free_child(input, &pipe);
	dup2(pipe.fd[pipe.i][0], 0);
	dup2(pipe.fd[pipe.i + 1][1], 1);
	close_pipes(pipe.fd, pipe.fd_count - 1);
	if (execve(cmd, input, env) == -1)
		free_child(input, &pipe);
}

void	run_child_last(t_pipex pipe, int argc, char **argv, char **env)
{
	int		file;
	char	**input;
	char	*cmd;

	input = ft_split(argv[argc - 2], ' ');
	cmd = find_cmd(input[0], env);
	if (cmd == NULL)
		free_child(input, &pipe);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		file = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		file = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror(argv[argc - 1]);
		free_child(input, &pipe);
	}
	dup2(pipe.fd[pipe.i][0], 0);
	dup2(file, 1);
	close_pipes(pipe.fd, pipe.fd_count - 1);
	if (execve(cmd, input, env) == -1)
		free_child(input, &pipe);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipe;

	pipex_init(&pipe, argv, argc);
	pipe.pid1 = fork();
	if (pipe.pid1 == 0)
		run_child_first(pipe, argv, envp);
	waitpid(pipe.pid1, NULL, 0);
	if ((argc > 5 && pipe.here_doc == 0) || (argc > 6 && pipe.here_doc == 1))
	{
		while (pipe.i < argc - 5)
		{
			pipe.pidn = fork();
			if (pipe.pidn == 0)
				run_child_middle(pipe, ft_split(argv[pipe.i + 3], ' '), envp);
			pipe.i++;
		}
	}
	pipe.pid2 = fork();
	if (pipe.pid2 == 0)
		run_child_last(pipe, argc, argv, envp);
	free_pipes(pipe.fd, pipe.fd_count - 1);
	waitpid(pipe.pidn, NULL, 0);
	waitpid(pipe.pid2, NULL, 0);
	return (0);
}
