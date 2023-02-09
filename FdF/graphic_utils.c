/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:14:57 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/30 11:15:01 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	mercator(float *x, float *y, float *z, t_map map)
{
	float x_norm;
	float y_norm;
	float theta;
	float phi;

	map.radius = map.colouns * map.zoom / (M_PI * 2);
	x_norm = *x / map.colouns;
	y_norm = *y / map.rows;
	theta = y_norm * M_PI;
	phi = x_norm * 2 * M_PI;
	*z /= 2;
	*x = (map.radius + *z) * sin(theta) * cos(phi);
	*y = (map.radius + *z) * sin(theta) * sin(phi);
	*z = (map.radius + *z) * cos(theta);
}

void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	zoom(t_map *map, float *x1, float *y1)
{
	map->x *= map->zoom;
	map->y *= map->zoom;
	*x1 *= map->zoom;
	*y1 *= map->zoom;
}

void	shift(t_map *map, float *x1, float *y1)
{
	map->x += map->x_offset;
	map->y += map->y_offset;
	*x1 += map->x_offset;
	*y1 += map->y_offset;
}

void	rotation(t_map *map, float *x1, float *y1)
{
	float	x_shift;
	float	y_shift;
	float	x1_shift;
	float	y1_shift;

	x_shift = map->x - map->colouns / 2;
	y_shift = map->y - map->rows / 2;
	x1_shift = *x1 - map->colouns / 2;
	y1_shift = *y1 - map->rows / 2;
	map->x = (x_shift * cos(map->rotation) - y_shift * sin(map->rotation));
	map->y = (y_shift * cos(map->rotation) + x_shift * sin(map->rotation));
	*x1 = (x1_shift * cos(map->rotation) - y1_shift * sin(map->rotation));
	*y1 = (y1_shift * cos(map->rotation) + x1_shift * sin(map->rotation));
}
