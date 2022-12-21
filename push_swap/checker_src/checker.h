/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:03:20 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/02 10:03:26 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

void		swap(t_stack *x);
void		shift(t_stack *x);
void		rev_shift(t_stack *x);
void		push(t_stack *x, t_stack *y);
void		dshift(t_stack *a, t_stack *b, int rot);

long int	long_atoi(char *str);
int			find_the_min(t_stack *a, int c_size);
int			find_min_max(t_stack *a, int swap);
int			ft_is_digit(char *str);
int			ft_strcmp(char *s1, char *s2);

#endif
