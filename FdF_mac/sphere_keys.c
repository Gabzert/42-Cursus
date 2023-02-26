/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_keys.c                                     :+:      :+:    :+:   */
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
	if (key == 126)
		all->map.x_angle -= 0.05;
	else if (key == 125)
		all->map.x_angle += 0.05;
	create_image(all, &all->map);
}

void	rot_y(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	if (key == 124)
		all->map.y_angle -= 0.05;
	else if (key == 123)
		all->map.y_angle += 0.05;
	create_image(all, &all->map);
}

void	rot_z(int key, t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	if (key == 12)
		all->map.z_angle -= 0.05;
	else if (key == 14)
		all->map.z_angle += 0.05;
	create_image(all, &all->map);
}
