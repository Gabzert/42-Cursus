/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:07:44 by gfantech          #+#    #+#             */
/*   Updated: 2023/01/24 18:07:47 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_map {
	int		rows;
	int		colouns;
	int		**points;
	int		**colors;
	int		zoom;
	int		x_offset;
	int		y_offset;
	float	angle;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	float	rotation;
	float	x;
	float	y;
	bool	mercator;
	float	radius;
	int	lon_step;
	int	lat_step;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
}				t_vars;

typedef struct s_line {
	float	x_step;
	float	y_step;
	float	max;
	float		z;
	float		z1;
	int		color;
}				t_line;

typedef struct s_everything {
	t_data	data;
	t_vars	vars;
	t_map	map;
}				t_everything;

void	create_matrix(t_map *data, int fd);
void	read_map(int fd, t_map *data);

/************/
/*  KEYS   */
/************/
void	move(int key, t_everything *all);
void	change_angle(int key, t_everything *all);
void	rotate(int key, t_everything *all);
int		scroll(int button, int x, int y, t_everything *all);
void	change_projection(t_everything *all);

/****************/
/*  WIN_UTILS   */
/****************/
int		key_hooks(int keycode, t_everything *all);
int		terminate(t_vars *vars);
void	destroy(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/**************/
/*  G_UTILS   */
/**************/
void	isometric(float *x, float *y, int z, float angle);
void	mercator(float *x, float *y, float *z, t_map map);
void	zoom(t_map *map, float *x1, float *y1);
void	shift(t_map *map, float *x1, float *y1);
void	rotation(t_map *map, float *x1, float *y1);

/*******************/
/*  SPHERE UTILS   */
/*******************/
void	rotX(int key, t_everything *all);
void	rotY(int key, t_everything *all);
void	rotZ(int key, t_everything *all);
void	rotateX(float *y, float *z, float angle);
void	rotateY(float *x, float *z, float angle);
void	rotateZ(float *x, float *y, float angle);

/************/
/*  UTILS   */
/************/
float	find_max(float a, float b);
char	*get_color(char *point);
char	*get_value(char *point);
int		create_trgb(int t, int r, int g, int b);
int		hex_convert(char *color);

/************/
/* UTILS 2  */
/************/
void	map_init(t_map *map);
void	create_image(t_everything *all, t_map *map);
void	isometric_handler(t_map *map, t_line *bres, float *x1, float *y1);
void	mercator_handler(t_map *map, t_line *bres, float *x1, float *y1);

#endif
