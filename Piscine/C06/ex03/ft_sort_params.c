/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:28:20 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/12 10:28:25 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include <stdbool.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str = str + 1;
	}
	write(1, "\n", 1);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while (s1[c] == s2[c] && (s1[c] != '\0' || s2[c] != '\0'))
	{
		c++;
	}
	return (s1[c] - s2[c]);
}

void	ft_sort_tab(char **tab, int size)
{
	bool	out;
	int		i;

	i = 0;
	out = false;
	while (!out)
	{
		i = 0;
		out = true;
		while (i < (size - 1))
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
				out = false;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	c;		

	c = 1;
	ft_sort_tab(argv, argc);
	while (c < argc)
	{	
		ft_putstr(argv[c]);
		c++;
	}
	return (0);
}
