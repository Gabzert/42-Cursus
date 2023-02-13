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

int	zoom_check(t_map map, int zoom)
{
	float	z;
	float	x_shift;
	float	y_shift;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j <= map.rows - 1 && zoom > 0)
	{
		while (i <= map.colouns - 1 && zoom > 0)
		{
			map.x = i;
			map.y = j;
			z = map.points[j][i] * (zoom / 2);
			x_shift = map.x - map.colouns / 2;
			y_shift = map.y - map.rows / 2;
			map.x = (x_shift * cos(map.rotation) - y_shift * sin(map.rotation));
			map.y = (y_shift * cos(map.rotation) + x_shift * sin(map.rotation));
			map.x *= zoom;
			map.y *= zoom;
			isometric(&map.x, &map.y, z, map.angle);
			map.x += map.x_offset;
			map.y += map.y_offset;
			if ((map.x > WIN_L || map.x < 0) || (map.y > WIN_H || map.y < 0))
			{
				zoom -= 0.5;
				if (i != 0)
					i -= 1;
			}
			else
				i++;
		}
		i = 0;
		j++;
	}
	return (zoom);
}

void	map_init(t_map *map)
{
	map->y_offset = 540;
	map->x_offset = 960;
	map->rotation = 0;
	map->angle = 1;
	map->mercator = false;
	map->color = false;
	map->x_angle = 1.55;
	map->y_angle = 0;
	map->z_angle = 0;
	map->mer_fix = 1;
	map->zoom = zoom_check(*map, 100);
	map->radius = map->colouns * map->zoom / (M_PI * 2);
}

void	isometric_handler(t_map *map, t_line *bres, float *x1, float *y1)
{
	rotation(map, x1, y1);
	zoom(map, x1, y1);
	isometric(&map->x, &map->y, bres->z, map->angle);
	isometric(x1, y1, bres->z1, map->angle);
}

void	mercator_handler(t_map *map, t_line *bres, float *x1, float *y1)
{
	mercator(&map->x, &map->y, &bres->z, *map);
	mercator(x1, y1, &bres->z1, *map);
	rotate_x(&map->y, &bres->z, map->x_angle);
	rotate_y(&map->x, &bres->z, map->y_angle);
	rotate_z(&map->x, &map->y, map->z_angle);
	rotate_z(y1, &bres->z1, map->x_angle);
	rotate_z(x1, &bres->z1, map->y_angle);
	rotate_z(x1, y1, map->z_angle);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->points[i]);
		free(map->colors[i]);
		i++;
	}
	free(map->points);
	free(map->colors);
}
