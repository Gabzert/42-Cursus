/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:18:46 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 09:18:56 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char str)
{
	int	controllo;

	controllo = 1;
	if ((str < 'a' || str > 'z') && (str > 'Z' || str < 'A'))
		controllo = 0;
	return (controllo);
}

int	is_num(char str)
{
	int	controllo;

	controllo = 1;
	if ((str > '9' || str < '0'))
		controllo = 0;
	return (controllo);
}

char	*ft_strcapitalize(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0' )
	{
		if (is_alpha(str[c - 1]) == 0 && is_num(str[c - 1]) == 0)
		{
			if ((str[c] <= 'z' && str[c] >= 'a'))
				str[c] = str[c] - 32;
		}
		else
		{
			if ((str[c] <= 'Z' && str[c] >= 'A'))
				str[c] = str[c] + 32;
		}
		c++;
	}
	return (str);
}
