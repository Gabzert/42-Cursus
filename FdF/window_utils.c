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

void	destroy(t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	mlx_destroy_window(all->vars.mlx, all->vars.mlx_win);
	mlx_destroy_display(all->vars.mlx);
	free(all->vars.mlx);
	free_map(&all->map);
	ft_printf("quit\n");
	exit(0);
}

int	key_hooks(int keycode, t_everything *all)
{
	if (keycode == 65307)
		destroy(all);
	else if (keycode == 115 || keycode == 119
		|| keycode == 97 || keycode == 100)
		move(keycode, all);
	else if (keycode == 65364 || keycode == 65362)
	{
		if (all->map.mercator == false)
			change_angle(keycode, all);
		else
			rot_x(keycode, all);
	}
	else if (keycode == 65363 || keycode == 65361)
	{
		if (all->map.mercator == false)
			rotate(keycode, all);
		else
			rot_y(keycode, all);
	}
	else if (keycode == 112)
		change_projection(all);
	else if (keycode == 113 || keycode == 101)
		rot_z(keycode, all);
	else if (keycode == 99)
		change_color(all);
	return (0);
}

int	terminate(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
