/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:06:02 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/24 18:06:05 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	bresenham(float x1, float y1, t_map map, t_data *data)
{
	t_line	bres;
	map.radius = map.colouns * map.zoom / (M_PI * 2);
	bres.color = map.colors[(int)map.y][(int)map.x];
	bres.z = map.points[(int)map.y][(int)map.x] * (map.zoom / 2);
	bres.z1 = map.points[(int)y1][(int)x1] * (map.zoom / 2);
	if (map.mercator == false)
	{
		rotation(&map, &x1, &y1);
		zoom(&map, &x1, &y1);
		isometric(&map.x, &map.y, bres.z, map.angle);
		isometric(&x1, &y1, bres.z1, map.angle);
	}
	else
	{
		mercator(&map.x, &map.y, &bres.z, map);
		mercator(&x1, &y1, &bres.z1, map);
		rotateX(&map.y, &bres.z, map.x_angle);
		rotateY(&map.x, &bres.z, map.y_angle);
		rotateZ(&map.x, &map.y, map.z_angle);
		rotateX(&y1, &bres.z1, map.x_angle);
		rotateY(&x1, &bres.z1, map.y_angle);
		rotateZ(&x1, &y1, map.z_angle);
	}
	bres.x_step = x1 - map.x;
	bres.y_step = y1 - map.y;
	shift(&map, &x1, &y1);
	bres.max = find_max(bres.x_step, bres.y_step);
	bres.x_step /= bres.max;
	bres.y_step /= bres.max;
	while ((int)(map.x - x1) || (int)(map.y - y1))
	{
		if ((map.x > 0 && map.x < 1920) && (map.y > 0 && map.y < 1070))
			my_mlx_pixel_put(data, map.x, map.y, bres.color);
		map.x += bres.x_step;
		map.y += bres.y_step;
	}
}

void	create_image(t_everything *all, t_map *map)
{
	map->x = 0;
	map->y = 0;
	all->data.img = mlx_new_image(all->vars.mlx, 1920, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	while (map->y <= map->rows - 1)
	{

		while (map->x <= map->colouns - 1)
		{
			if (map->x != map->colouns - 1)
				bresenham(map->x + 1, map->y, *map, &all->data);
			if (map->y != map->rows - 1)
				bresenham(map->x, map->y + 1, *map, &all->data);
			map->x++;
		}
		map->x = 0;
		map->y++;
	}
	mlx_put_image_to_window(all->vars.mlx, all->vars.mlx_win,
		all->data.img, 0, 0);
}

int	main(int argc, char **argv)
{
	int				fd_map;
	t_map			map;
	t_vars			vars;
	t_everything	all;

	if (argc > 2)
		return (0);
	fd_map = open(argv[1], O_RDONLY);
	read_map(fd_map, &map);
	map_init(&map);
	close(fd_map);
	fd_map = open(argv[1], O_RDONLY);
	create_matrix(&map, fd_map);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	all.vars = vars;
	create_image(&all, &map);
	all.map = map;
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hooks, &all);
	mlx_mouse_hook(vars.mlx_win, scroll, &all);
	mlx_hook(vars.mlx_win, 17, 0L, terminate, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
