/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:54:51 by gfantech          #+#    #+#             */
/*   Updated: 2022/12/22 11:54:54 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	double_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strncmp(cmd, "rr\n", 3) == 0)
	{
		dshift(a, b, 0);
		return (0);
	}
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		dshift(a, b, 1);
		return (0);
	}
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
	{
		rev_shift(a);
		return (0);
	}
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
	{
		rev_shift(b);
		return (0);
	}
	return (1);
}

int	cmd_handler(t_stack *a, t_stack *b, char *cmd)
{
	while (cmd)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		else if (ft_strncmp(cmd, "sa\n", 3) == 0)
			swap(a);
		else if (ft_strncmp(cmd, "sb\n", 3) == 0)
			swap(b);
		else if (ft_strncmp(cmd, "pb\n", 3) == 0)
			push(a, b);
		else if (ft_strncmp(cmd, "pa\n", 3) == 0)
			push(b, a);
		else if (ft_strncmp(cmd, "ra\n", 3) == 0)
			shift(a);
		else if (ft_strncmp(cmd, "rb\n", 3) == 0)
			shift(b);
		else if (double_cmd(a, b, cmd) == 1)
			return (1);
		free(cmd);
	}
	return (0);
}
