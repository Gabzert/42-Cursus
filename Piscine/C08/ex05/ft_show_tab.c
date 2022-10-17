/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:24 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/16 16:52:41 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str = str + 1;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	size_print;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		size_print = par[i].size + '0';
		write(1, &size_print, 2);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
