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


void	read_map(int fd, t_map_data *data)
{
	char	*str;
	char	**temp;
	int		check;

	data->rows = 0;
	data->colouns = 0;
	check = 0;
	str = get_next_line(fd);
	temp = ft_split(str, ' ');
	while (temp)
	{
		temp++;
		data->colouns++;
	}
	free (temp);
	while (str)
	{
		str = get_next_line(fd);
		data->rows++;
		temp = ft_split(str, ' ');
		while (temp[check])
			check++;
		if (check != data->colouns)
			exit(1);
		check = 0;
	}
}

int	**create_matrix(t_map_data data, int fd)
{
	int	i;
	int	j;
	int	**map;
	char	*row;
	char	**columns

	i = 0;
	j = 0;
	map = (int **)malloc((data.rows) * sizeof(int *));
	while (i < rows)
	{
		map[i] = (int *)malloc(data.colouns * sizeof(int));
		row = get_next_line(fd);
		columns = ft_split(row, ' ');
		while (j < colouns)
		{
			map[i][j] = ft_atoi(columns[j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}


int	main(int argc, char **argv)
{
	int	fd_map;
	int	**points;
	int	**colors;
	t_map_data map;
	t_vars	vars;
	t_data	img;
	t_color	rgb;
	t_everything	all;
	
	fd_map = open(argv[1], O_RDONLY);
	read_map(fd_map, &map);
	points = create_matrix(map, fd_map);

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 720, "Hello world!");
	create_image(points);
	mlx_hook(vars.mlx_win, 2, 1L<<0, key_hooks, &all);
	mlx_hook(vars.mlx_win, 17, 0L, terminate, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
