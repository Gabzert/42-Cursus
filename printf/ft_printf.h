/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:34:22 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/13 14:34:28 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		precision;
	char	spec;
	char	parse;
}	t_format;

int	ft_printchr(int c, int *count);
int	ft_printstr(char *str, int *count);
int	ft_printnum(int val, int *count);
int	ft_printhex(unsigned int n, char c, int *count);
int	ft_printmem(void *ptr, int *count);
int	ft_printf(const char *str, ...);

#endif
