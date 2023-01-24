/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:56:21 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/19 16:56:27 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	put_color(t_vars vars, t_data img, t_color rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 1700)
	{
		rgb.color = create_trgb(0, rgb.red, rgb.green, rgb.blue);
		while (j < 600)
		{
			my_mlx_pixel_put(&img, i + 140, j + 60, rgb.color);
			j++;
		}
			if ((rgb.red == 255 || rgb.red > 0) && rgb.green != 255 && rgb.blue == 0)
				rgb.green++;
			else if (rgb.red != 0 && (rgb.green == 255 || rgb.green > 0) && rgb.blue == 0)
				rgb.red--;
			else if (rgb.red == 0 && (rgb.green == 255 || rgb.green > 0) && rgb.blue != 255)
				rgb.blue++;
			else if (rgb.red == 0 && rgb.green != 0 && (rgb.blue == 255 || rgb.blue > 0))
				rgb.green--;
			else if (rgb.red != 255 && rgb.green == 0 && (rgb.blue == 255 || rgb.blue > 0))
				rgb.red++;
			else if ((rgb.red == 255 || rgb.red > 0) && rgb.green == 0 && rgb.blue != 0)
				rgb.blue--;
		j = 0;
		i++;
	}
	
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_color	rgb;
	t_everything	all;

	rgb.red = 255;
	rgb.blue = 0;
	rgb.green = 0;
	
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 720, "Hello world!");
	
	img.img = mlx_new_image(vars.mlx, 1920, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	
	all.data = img;
	all.color = rgb;
	all.vars = vars;
	
	put_color(vars, img, rgb);

	
	mlx_hook(vars.mlx_win, 2, 1L<<0, key_hooks, &all);
	mlx_hook(vars.mlx_win, 17, 0L, terminate, &vars);
	mlx_loop(vars.mlx);
	return(0);
}







