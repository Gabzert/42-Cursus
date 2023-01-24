



#include "test.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	ft_printf("quit\n");
	exit(0);
}

void	new_image(t_vars *vars)
{
	t_data	img;
	int	xpm_x;
	int	xpm_y;
	
	img.img = mlx_xpm_file_to_image(vars->mlx,"NO.xpm",&xpm_x,&xpm_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 700, 0);
}

int	loop_color(t_everything *all)
{
	if ((all->color.red == 255 || all->color.red > 0) && all->color.green != 255 && all->color.blue == 0)
		all->color.green++;
	else if (all->color.red != 0 && (all->color.green == 255 || all->color.green > 0) && all->color.blue == 0)
		all->color.red--;
	else if (all->color.red == 0 && (all->color.green == 255 || all->color.green > 0) && all->color.blue != 255)
		all->color.blue++;
	else if (all->color.red == 0 && all->color.green != 0 && (all->color.blue == 255 || all->color.blue > 0))
		all->color.green--;
	else if (all->color.red != 255 && all->color.green == 0 && (all->color.blue == 255 || all->color.blue > 0))
		all->color.red++;
	else if ((all->color.red == 255 || all->color.red > 0) && all->color.green == 0 && all->color.blue != 0)
		all->color.blue--;
	mlx_destroy_image(all->vars.mlx, all->data.img);
	all->data.img = mlx_new_image(all->vars.mlx, 1920, 720);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
	put_color(all->vars, all->data, all->color);
	return (0);
}

int	key_hooks(int keycode, t_everything *all)
{
	if (keycode == 65307)
		destroy(&all->vars);
	else if (keycode == 115)	
		mlx_loop_hook(all->vars.mlx, loop_color, all);
	else if (keycode == 105)
		new_image(&all->vars);
	return (0);
}

int	terminate(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
