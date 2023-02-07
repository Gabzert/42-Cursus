/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:58:29 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/30 13:58:35 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	ft_printf("quit\n");
	exit(0);
}

int	key_hooks(int keycode, t_everything *all)
{
	if (keycode == 65307)
		destroy(&all->vars);
	else if (keycode == 115 || keycode == 119
		|| keycode == 97 || keycode == 100)
		move(keycode, all);
	else if (keycode == 65364 || keycode == 65362)
	{
		if (all->map.mercator == false)
			change_angle(keycode, all);
		else
			rotX(keycode, all);
	}
	else if (keycode == 65363 || keycode == 65361)
	{
		if (all->map.mercator == false)
			rotate(keycode, all);
		else
			rotY(keycode, all);
	}
	else if (keycode == 112)
		change_projection(all);
	else if (keycode == 113 || keycode == 101)
		rotZ(keycode, all);
	return (0);
}

int	terminate(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
