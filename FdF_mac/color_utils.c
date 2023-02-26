/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:20:03 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/02 12:20:09 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_min_max(t_map map, int swap)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (j <= map.rows - 1)
	{
		while (i <= map.colouns - 1)
		{
			if (swap == 1 && map.points[j][i] > z)
				z = map.points[j][i];
			else if (swap == 0 && map.points[j][i] < z)
				z = map.points[j][i];
			i++;
		}
		i = 0;
		j++;
	}
	return (z);
}

static void	determine_color(t_map *map, int j, int i)
{
	int	z_max;
	z_max = find_min_max(*map, 1);
	if (map->points[j][i] < z_max * 0.02)
		map->colors[j][i] = hex_convert(ft_strdup("0xFF"));
	else if (map->points[j][i] >= z_max * 0.02
		&& map->points[j][i] < z_max * 0.15)
		map->colors[j][i] = hex_convert(ft_strdup("0xFF00"));
	else if (map->points[j][i] >= z_max * 0.15
		&& map->points[j][i] < z_max * 0.35)
		map->colors[j][i] = hex_convert(ft_strdup("0x642D13"));
	else if (map->points[j][i] >= z_max * 0.35
		&& map->points[j][i] < z_max * 0.5)
		map->colors[j][i] = hex_convert(ft_strdup("0x484848"));
	else if (map->points[j][i] >= z_max * 0.5)
		map->colors[j][i] = hex_convert(ft_strdup("0xFFFFFF"));
}

static void	colorize(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= map->rows - 1)
	{
		while (i <= map->colouns - 1)
		{
			if (map->color == true)
				determine_color(map, j, i);
			else
				map->colors[j][i] = hex_convert(ft_strdup("0x00FFFFFF"));
			i++;
		}
		i = 0;
		j++;
	}
}

void	change_color(t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	if (all->map.color == false)
	{
		all->map.color = true;
		colorize(&all->map);
	}
	else
	{
		all->map.color = false;
		colorize(&all->map);
	}
	create_image(all, &all->map);
}
