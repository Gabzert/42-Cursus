#ifndef TEST_H
# define TEST_H

#include <mlx.h>
#include "libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
}				t_vars;

typedef struct	s_color {
	int	color;
	int	red;
	int	green;
	int	blue;
}		t_color;

typedef struct	s_everything {
	t_data	data;
	t_vars	vars;
	t_color	color;
}				t_everything;


/****************/
/*    UTILS     */
/****************/

int	create_trgb(int t, int r, int g, int b);
void	destroy(t_vars *vars);
int	terminate(t_vars *vars);
int	key_hooks(int keycode, t_everything *all);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


int	put_color(t_vars vars, t_data img, t_color rgb);

#endif
