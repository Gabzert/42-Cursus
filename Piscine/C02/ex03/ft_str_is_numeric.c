/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:51:56 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/10 17:54:38 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	c;
	int	controllo;

	controllo = 1;
	c = 0;
	while (str[c] != '\0' )
	{
		if ((str[c] > '9' && str[c] < '0'))
		{
			controllo = 0;
			break ;
		}
		c++;
	}
	return (controllo);
}
