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
/*
void	mercator(float *x, float *y, int *z, t_map map)
{
	float	lat;
	float	lon;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map.colouns * map.zoom - 1);
	steps_y = M_PI / (map.rows * map.zoom);
	*z -= ((*x * *x) + (*y * *y));

	lon = -*x * steps_x;
	if (*y > 0)
		lat = (*y + ((map.rows * map.zoom) / 2)) * steps_y - 0.5 * steps_y;
	else
		lat = (*y + ((map.rows * map.zoom) / 2) - 1) * steps_y + 0.5 * steps_y;
	*x = (map.radius + *z) * cos(lon) * sin(lat);
  	*y = (map.radius + *z) * sin(lon) * sin(lat);
  	*z = (map.radius + *z) * sin(y_norm);
}

void	mercator(float *x, float *y, int *z, t_map map)
{
	float	xc;
	float	yc;
	float	x_shift;
	float	y_shift;
	float	theta;
	float	phi;
	double	r;
	
	(void) z;
	xc = map.colouns / 2;
	yc = map.rows / 2;
	x_shift = *x + xc;
	y_shift = *y + yc;
	
	r = sqrt(x_shift * x_shift + y_shift * y_shift);
	theta = atan2(y_shift, x_shift);
	phi = acos(r);
	*x = r * sin(phi) * cos(theta);
	*y = r * sin(phi) * sin(theta);
}
void	mercator(float *x, float *y, int *z, t_map map)
{
	float	lon;
	float	lat;

	lon = atan2(*y , *x);
	lat = atan2(*z, sqrt(*x * *x + *y * *y));
	*x = map.radius * cos(lat) * sin(lon);
  	*y = map.radius * sin(lat) * sin(lon);
  	*z = map.radius * cos(lat);
}
void	mercator(float *x, float *y, int *z, t_map map)
{
	float	xs;
	float	ys;
	float	theta;
	float	phi;

	xs = *x / map.radius;
	ys = *y / map.radius;
	theta = acos(*z / map.radius);
	phi = atan2(ys,xs);
	*x = (map.radius) * sin(theta) * cos(phi);
  	*y = (map.radius) * sin(theta) * sin(phi);
//  	*z = (map.radius) * sin(y_norm);
}
void	mercator(float *x, float *y, int *z, t_map map)
{
	float	x_norm;
	float	y_norm;

	x_norm = *x / map.colouns;
	y_norm = *y / map.rows;
	*x = (map.radius + *z) * cos(y_norm) * cos(x_norm);
  	*y = (map.radius + *z) * cos(y_norm) * sin(x_norm);
  	*z = (map.radius + *z) * sin(y_norm);
}
*/


void mercator(float *x, float *y, float *z, t_map map)
{
    float x_norm;
    float y_norm;
    float theta;
    float phi;

    x_norm = *x / map.colouns;
    y_norm = *y / map.rows;
    theta = y_norm * M_PI;
    phi = x_norm * 2 * M_PI;
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
