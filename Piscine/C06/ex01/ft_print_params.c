/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:47:19 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/12 09:47:30 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str = str + 1;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	c;		

	c = 1;
	while (c < argc)
	{
		ft_putstr(argv[c]);
		c++;
	}
	return (0);
}
