/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:09:39 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/12 10:09:44 by gfantech         ###   ########.fr       */
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

	c = argc - 1;
	while (c > 0)
	{
		ft_putstr(argv[c]);
		c--;
	}
	return (0);
}
