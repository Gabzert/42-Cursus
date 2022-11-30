/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:58:55 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/15 11:58:59 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

void	push(t_stack *x, t_stack *y, int side);
void	shift(t_stack *x, int side);
void	rev_shift(t_stack *x, int side);
void	swap(t_stack *x, int side);
void	dshift(t_stack *a, t_stack *b, int rot);

void	smart_shift(t_stack *x, t_stack *y, int num, int side);
int		adjust_b(t_stack *b, int num);
void	fix_b(t_stack *b, t_stack *a, int num);

void	sort(t_stack *a, t_stack *b);
int		sort_check(t_stack *a);
void	small_sort2(t_stack *a);
void	small_sort3(t_stack *a);
void	small_sort(t_stack *a, t_stack *b);

int		find_min_max(t_stack *a, int swap);
int		ft_is_digit(char *str);
int		ft_strcmp(char *s1, char *s2);
int		input_check(int argc, char **argv);
int		find_first(t_stack *a, int c_max, int c_min, int side);

#endif
