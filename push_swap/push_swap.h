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
	int	*chunk1;
	int	*chunk2;
	int	*chunk3;
	int	*chunk4;
	int	c_size;
}		t_stack;

void	push(t_stack *x, t_stack *y, int side);
void	shift(t_stack *x, int side);
void	rev_shift(t_stack *x, int side);
void	swap(t_stack *x, int side);
void	dshift(t_stack *a, t_stack *b, int rot);

/****************/
/*    GROUPS    */
/****************/
int		groups_init(t_stack *a);
void	groups_fill(t_stack *a);
int		which_group(t_stack *a, int n);
int		group_check(int *group, int n, int size);

int		*which_chunk(t_stack *a, int n);
int		*next_half(int *group, int n, int size);
int		find_in_chunk(int *group, int n, int size);
int		group_empty(t_stack *b, int *group);

/*********************/
/*    SMART SHIFT    */
/*********************/

void	smart_shift(t_stack *x, t_stack *y, int num, int side);
int		adjust(t_stack *x, int num);
void	fix(t_stack *x, int num);

/****************/
/*    UTILS     */
/****************/

int		find_the_min(t_stack *a, int c_size);
int		find_min_max(t_stack *a, int swap);
int		ft_is_digit(char *str);
int		ft_strcmp(char *s1, char *s2);
long		long_atoi(char *str);

/********************/
/*    SMALL SORT    */
/********************/

void	sort(t_stack *a, t_stack *b);
int		sort_check(t_stack *a);
void	small_sort2(t_stack *a);
void	small_sort3(t_stack *a);
void	small_sort(t_stack *a, t_stack *b);

#endif
