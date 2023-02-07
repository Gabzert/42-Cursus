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
/*
int	zoom_check(t_map map)
{
	int	a[2];
	int	b[2];
	int	c[2];
	int	d[2];

	while (1)
	{	
		a[0] = map.x_offset;
		a[1] = map.y_offset;
		b[0] = map.colouns + map.x_offset;
		b[1] = map.y_offset;
		c[0] = map.x_offset;
		c[1] = map.rows + map.y_offset;
		d[0] = map.colouns + map.x_offset;
		d[1] = map.rows + map.y_offset;
		a[0] *= map.zoom;
		a[1] *= map.zoom;
		b[0] *= map.zoom;
		b[1] *= map.zoom;
		c[0] *= map.zoom;
		c[1] *= map.zoom;
		d[0] *= map.zoom;
		d[1] *= map.zoom;
		if (a[0] >= 1900 || b[1] > 1060)
			map.zoom -= 1;
		else
			break;
	}
	return (map.zoom);
}
*/
void	map_init(t_map *map)
{
	map->y_offset = 540 - (map->rows / 2);
	map->x_offset = 960 - (map->colouns / 2);
	map->zoom = 30;
	map->angle = 0.8;
	map->rotation = 0;
	map->radius = map->colouns * map->zoom / (M_PI * 2);
//	map->radius = 200;
	map->mercator = false;
	map->x_angle = 0;
	map->y_angle = 0;
	map->z_angle = 0;
}

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
