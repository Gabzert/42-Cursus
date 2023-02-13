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

void	colorize(t_map *map)
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
			{
				if (map->points[j][i] <= 10)
					map->colors[j][i] = hex_convert("0xFF");
				else if (map->points[j][i] >= 11 && map->points[j][i] <= 40)
					map->colors[j][i] = hex_convert("0xFF00");
				else if (map->points[j][i] >= 41 && map->points[j][i] <= 60)
					map->colors[j][i] = hex_convert("0x753900");
				else if (map->points[j][i] >= 61 && map->points[j][i] <= 80)
					map->colors[j][i] = hex_convert("0x484848");
				else if (map->points[j][i] >= 81)
					map->colors[j][i] = hex_convert("0xFFFFFF");
			}
			else
				map->colors[j][i] = hex_convert("0xFFFFFF");
			i++;
		}
		i = 0;
		j++;
	}
}

void	change_color(t_everything *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, WIN_L, WIN_H);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
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
