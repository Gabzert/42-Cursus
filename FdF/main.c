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

void	read_map(int fd, t_map *data)
{
	char	*str;
	char	**temp;
	int		i;

	data->rows = 0;
	data->colouns = 0;
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		data->rows++;
		temp = ft_split(str, ' ');
		while (temp[i])
			i++;
		if (data->colouns == 0)
			data->colouns = i;
		if (i != data->colouns)
			exit(1);
		i = 0;
	}
}


void	create_matrix(t_map *data, int fd)
{
	int		i;
	int		j;
	char	**columns;

	i = 0;
	j = 0;
	data->points = (int **)malloc((data->rows) * sizeof(int *));
	data->colors = (int **)malloc((data->rows) * sizeof(int *));
	while (i < data->rows)
	{
		data->points[i] = (int *)malloc(data->colouns * sizeof(int));
		data->colors[i] = (int *)malloc(data->colouns * sizeof(int));
		columns = ft_split(get_next_line(fd), ' ');
		while (j < data->colouns)
		{
			data->points[i][j] = ft_atoi(get_value(columns[j]));
			data->colors[i][j] = hex_convert(get_color(columns[j]));
			j++;
		}
		free(columns);
		j = 0;
		i++;
	}
}

void	bresenham(float x1, float y1, t_map map, t_data *data)
{
	t_line	bres;
	map.radius = map.colouns * map.zoom / (M_PI * 2);
	bres.color = map.colors[(int)map.y][(int)map.x];
	bres.z = map.points[(int)map.y][(int)map.x] * (map.zoom / 2);
	bres.z1 = map.points[(int)y1][(int)x1] * (map.zoom / 2);
	if (map.mercator == false)
		isometric_handler(&map, &bres, &x1, &y1);
	else
		mercator_handler(&map, &bres, &x1, &y1);
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
	int	mer_fix;	

	mer_fix = 1;
	if (map->mercator == true)
		mer_fix = 0,
	map->x = 0;
	map->y = 0;
	all->data.img = mlx_new_image(all->vars.mlx, 1920, 1080);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	while (map->y <= map->rows - 1)
	{
		while (map->x <= map->colouns - mer_fix)
		{
			if (map->x != map->colouns - mer_fix)
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
