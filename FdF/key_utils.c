/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:59:43 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/30 13:59:45 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 115)
		all->map.y_offset += 10;
	else if (key == 119)
		all->map.y_offset -= 10;
	else if (key == 97)
		all->map.x_offset -= 10;
	else if (key == 100)
		all->map.x_offset += 10;
	create_image(all, &all->map);
}

void	change_angle(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 65364)
		all->map.angle -= 0.05;
	else if (key == 65362)
		all->map.angle += 0.05;
	create_image(all, &all->map);
}

int	scroll(int button, int x, int y, t_everything *all)
{
	(void) x;
	(void) y;
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (button == 4)
		all->map.zoom += 2;
	else if (button == 5)
		all->map.zoom -= 2;
	create_image(all, &all->map);
	return (0);
}

void	rotate(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 65363)
		all->map.rotation -= 0.05;
	else if (key == 65361)
		all->map.rotation += 0.05;
	create_image(all, &all->map);
}
