/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:31:02 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/05 11:31:04 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	convert(long n, char *res, int i)
{
	if (n != 0)
	{
		convert(n / 10, res, i - 1);
		res[i] = (n % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	long	n1;
	int		lenght;

	lenght = 0;
	n1 = n;
	while (n != 0)
	{
		n = n / 10;
		lenght++;
	}
	if (n1 < 0)
	{
		n1 = n1 * -1;
		lenght++;
		res = (char *)malloc((lenght + 1) * sizeof(char));
		res[0] = '-';
	}
	else if (n1 == 0)
		return ("0");
	else
		res = (char *)malloc((lenght + 1) * sizeof(char));
	convert(n1, res, lenght - 1);
	res[lenght] = '\0';
	return (res);
}
