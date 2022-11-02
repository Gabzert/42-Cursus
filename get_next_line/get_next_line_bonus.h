/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:48:18 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/26 15:48:21 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 5
# include <unistd.h>
# include <stdlib.h>

typedef struct s_lines
{
	int	fd;
	static char *offset;
}		t_lines;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*strcut(char *str);
char	*ft_realloc(char *str);

#endif
