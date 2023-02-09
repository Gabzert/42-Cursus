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

void	rotX(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 65364)
		all->map.x_angle -= 0.05;
	else if (key == 65362)
		all->map.x_angle += 0.05;
	create_image(all, &all->map);
}

void	rotY(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 65363)
		all->map.y_angle -= 0.05;
	else if (key == 65361)
		all->map.y_angle += 0.05;
	create_image(all, &all->map);
}

void	rotZ(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1980, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	if (key == 113)
		all->map.z_angle -= 0.05;
	else if (key == 101)
		all->map.z_angle += 0.05;
	create_image(all, &all->map);
}

void	rotateX(float *y, float *z, float angle)
{
	float y_new = *y * cos(angle) - *z * sin(angle);
	float z_new = *y * sin(angle) + *z * cos(angle);
	*y = y_new;
	*z = z_new;
}

void	rotateY(float *x, float *z, float angle)
{
	float x_new = *x * cos(angle) + *z * sin(angle);
	float z_new = - *x * sin(angle) + *z * cos(angle);
	*x = x_new;
	*z = z_new;
}

void	rotateZ(float *x, float *y, float angle)
{
	float x_new = *x * cos(angle) - *y * sin(angle);
	float y_new = *x * sin(angle) + *y * cos(angle);
	*x = x_new;
	*y = y_new;
}
