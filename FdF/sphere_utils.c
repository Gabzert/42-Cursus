/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:24:33 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/07 11:24:36 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	free(all->data.addr);
	all->data.img = mlx_new_image(all->vars.mlx, WIN_L, WIN_H);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 65364)
		all->map.x_angle -= 0.05;
	else if (key == 65362)
		all->map.x_angle += 0.05;
	create_image(all, &all->map);
}

void	rot_y(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	free(all->data.addr);
	all->data.img = mlx_new_image(all->vars.mlx, WIN_L, WIN_H);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 65363)
		all->map.y_angle -= 0.05;
	else if (key == 65361)
		all->map.y_angle += 0.05;
	create_image(all, &all->map);
}

void	rot_z(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	free(all->data.addr);
	all->data.img = mlx_new_image(all->vars.mlx, WIN_L, WIN_H);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 113)
		all->map.z_angle -= 0.05;
	else if (key == 101)
		all->map.z_angle += 0.05;
	create_image(all, &all->map);
}

void	rotate_x(float *y, float *z, float angle)
{
	float	y_new;
	float	z_new;

	y_new = *y * cos(angle) - *z * sin(angle);
	z_new = *y * sin(angle) + *z * cos(angle);
	*y = y_new;
	*z = z_new;
}

void	rotate_y(float *x, float *z, float angle)
{
	float	x_new;
	float	z_new;

	x_new = *x * cos(angle) + *z * sin(angle);
	z_new = *z * cos(angle) - *x * sin(angle);
	*x = x_new;
	*z = z_new;
}

void	rotate_z(float *x, float *y, float angle)
{
	float	x_new;
	float	y_new;

	x_new = *x * cos(angle) - *y * sin(angle);
	y_new = *x * sin(angle) + *y * cos(angle);
	*x = x_new;
	*y = y_new;
}
