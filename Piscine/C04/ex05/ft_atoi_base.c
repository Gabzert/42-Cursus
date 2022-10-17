/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:23:12 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/17 12:23:23 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char c)
{
	if (c == 32 || c == 9 || c == '\r' || c == '\v'
		|| c == '\n' || c == '\f')
		return (0);
	else
		return (1);
}

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

int	convert(char *base, char pos )
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
	while (convert(base, *str) != -1)
	{
		resolved = convert(base, *str);
		num *= radix;
		num += resolved;
		str++;
	}
	return (num * neg);
}
