

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

void	swap(t_stack *x);
void	shift(t_stack *x);
void	rev_shift(t_stack *x);
void	push(t_stack *x, t_stack *y);
void	dshift(t_stack *a, t_stack *b, int rot);

#endif