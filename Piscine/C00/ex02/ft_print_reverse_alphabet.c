/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:10:57 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/05 12:11:10 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	x;
	int		i;

	x = 'z';
	i = 0;
	while (i < 26)
	{
		write(1, &x, 1);
		x = x - 1;
		i++;
	}
}
