/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:20:03 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/02 12:20:09 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_check(t_map map)
{
	float z;
	float	x_shift;
	float	y_shift;

	map.x = 0;
	map.y = 0;
	while (map.x < map.colouns && map.y < map.rows)
	{
		z = map.points[(int)map.y][(int)map.x] * (map.zoom / 2);
		x_shift = map.x - map.colouns / 2;
		y_shift = map.y - map.rows / 2;
		map.x = (x_shift * cos(map.rotation) - y_shift * sin(map.rotation));
		map.y = (y_shift * cos(map.rotation) + x_shift * sin(map.rotation));
		map.x *= map.zoom;
		map.y *= map.zoom;
		isometric(&map.x, &map.y, z, map.angle);
		if ((map.x > 1910 || map.x < 10) || (map.y > 1070 || map.y < 10))
		{
			map.zoom -= 1;
			map.x = 0;
			map.y = 0;
		}
		else
		{
			map.x++;
			map.y++;
		}
	}
	return (map.zoom);
}

void	map_init(t_map *map)
{
	map->y_offset = 540 - (map->rows / 2);
	map->x_offset = 960 - (map->colouns / 2);
	map->zoom = 30;
	map->angle = 0.8;
	map->rotation = 0;
	map->radius = map->colouns * map->zoom / (M_PI * 2);
	map->mercator = false;
	map->x_angle = 0;
	map->y_angle = 0;
	map->z_angle = 0;
}

void	isometric_handler(t_map *map, t_line *bres, float *x1, float *y1)
{
		rotation(&map, x1, y1);
		zoom(&map, x1, y1);
		isometric(&map->x, &map->y, bres->z, map->angle);
		isometric(x1, y1, bres->z1, map->angle);
}


void	mercator_handler(t_map *map, t_line *bres, float *x1, float *y1)
{
		mercator(&map->x, &map->y, &bres->z, *map);
		mercator(x1, y1, &bres->z1, *map);
		rotateX(&map->y, &bres->z, map->x_angle);
		rotateY(&map->x, &bres->z, map->y_angle);
		rotateZ(&map->x, &map->y, map->z_angle);
		rotateX(y1, &bres->z1, map->x_angle);
		rotateY(x1, &bres->z1, map->y_angle);
		rotateZ(x1, y1, map->z_angle);
}

