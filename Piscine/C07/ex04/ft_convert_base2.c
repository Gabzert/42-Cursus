/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:27:22 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/17 17:30:29 by gfantech         ###   ########.fr       */
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

void	ft_rev_str_tab(char *tab, int size)
{
	int		c;
	char	temp;

	c = 0;
	if (tab[0] == '-')
	{
		size++;
		c++;
	}
	while (c < size / 2)
	{
		temp = *(tab + c);
		*(tab + c) = *(tab + (size - 1 - c));
		*(tab + (size - 1 - c)) = temp;
		c++;
	}
}
