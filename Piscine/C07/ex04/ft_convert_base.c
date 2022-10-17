/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:39:33 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/17 16:39:42 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		is_base_valid(char *str);
int		ft_strlen(char *str);
int		is_space(char c);
void	ft_rev_str_tab(char *tab, int size);

int	check_base(char *base, char pos )
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == pos)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	neg;
	int	radix;
	int	resolved;

	neg = 1;
	num = 0;
	while ('-' == *str || *str == '+' || is_space(*str) == 0)
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	if (is_base_valid(base) == 1)
		return (0);
	radix = ft_strlen(base);
	while (check_base(base, *str) != -1)
	{
		resolved = check_base(base, *str);
		num *= radix;
		num += resolved;
		str++;
	}
	return (num * neg);
}

char	*convert(int n, char *base, int radix)
{
	char	*final;
	int		s;

	final = (char *) malloc (sizeof (char) * 20);
	if (final == 0)
		return (0);
	s = 0;
	if (n < 0)
	{
		n *= -1;
		final[0] = '-';
		s++;
	}
	if (n == 0)
		final[0] = '0';
	while (n > 0)
	{
		final[s] = base[n % radix];
		n /= radix;
		s++;
	}
	return (final);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		radix;
	char	*inverted;
	int		s;

	if (is_base_valid(base) == 1)
		return (NULL);
	radix = ft_strlen(base);
	inverted = convert(nbr, base, radix);
	s = ft_strlen(inverted);
	ft_rev_str_tab(inverted, s);
	return (inverted);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{	
	int		mid;
	char	*final;

	mid = ft_atoi_base(nbr, base_from);
	if (mid == 0 && is_base_valid(base_from) == 1)
		return (NULL);
	final = ft_putnbr_base(mid, base_to);
	return (final);
}
