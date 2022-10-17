/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:48:50 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 13:49:04 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	is_base_valid(char *str)
{
	char	*curr;
	int		i;
	int		j;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (1);
	while (*curr)
	{
		if (*curr == '+' || *curr == '-')
			return (1);
		curr++;
	}
	i = 0;
	while (i < curr - str)
	{
		j = i + 1;
		while (j < curr - str)
			if (str[i] == str[j++])
				return (1);
		i++;
	}
	return (0);
}

void	convert(int n, char *base, int radix)
{
	int	temp;

	if (n == -2147483648)
	{
		convert(n / radix, base, radix);
		write(1, &(base[-(n % radix)]), 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		convert(-n, base, radix);
		return ;
	}
	if (n > 0)
	{
		temp = n % radix;
		n = n / radix;
		convert(n, base, radix);
		write(1, &base[temp], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	if (is_base_valid(base) == 1)
		return ;
	radix = ft_strlen(base);
	convert(nbr, base, radix);
}
