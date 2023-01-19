/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:56:44 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/21 11:56:46 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int	**fd;
	int	fd_count;
	int	pid1;
	int	pid2;
	int	pidn;
	int	i;
	int	here_doc;
}	t_pipex;

/****************/
/*    PIPE      */
/****************/

int		**create_pipe(int argc, char **argv, t_pipex *p);
void	close_pipes(int **fd, int i);
void	free_pipes(int **fd, int i);

/****************/
/*    UTILS     */
/****************/

char	*find_path(char **env);
char	*find_cmd(char *cmd, char **env);
void	free_child(char **input, t_pipex *pipe);
void	take_input(char *eof, int *file);
void	pipex_init(t_pipex *p, char **argv, int argc);

#endif
