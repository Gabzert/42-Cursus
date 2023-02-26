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

void	is_printable(t_map map, t_data *data, t_line bres)
{
	if ((map.x > 0 && map.x < WIN_L) && (map.y > 0 && map.y < WIN_H))
	{
		if (map.mercator == false)
			my_mlx_pixel_put(data, map.x, map.y, bres.color);
		else if (bres.z < 0)
			my_mlx_pixel_put(data, map.x, map.y, bres.color);
	}
}

void	destroy(t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	mlx_destroy_window(all->vars.mlx, all->vars.mlx_win);
//	mlx_destroy_display(all->vars.mlx);
	free(all->vars.mlx);
	free_map(&all->map);
	ft_printf("quit\n");
	exit(0);
}

int	key_hooks(int key, t_everything *all)
{
	if (key == 53)
		destroy(all);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		move(key, all);
	else if (key == 126 || key == 125)
	{
		if (all->map.mercator == false)
			change_angle(key, all);
		else
			rot_x(key, all);
	}
	else if (key == 123 || key == 124)
	{
		if (all->map.mercator == false)
			rotate(key, all);
		else
			rot_y(key, all);
	}
	else if (key == 35)
		change_projection(all);
	else if (key == 12 || key == 14)
		rot_z(key, all);
	else if (key == 8)
		change_color(all);
	return (0);
}

int	terminate(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
//	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
