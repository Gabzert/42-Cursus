/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:10:01 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/10 18:10:12 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_uppercase(char *str)
{
	int	c;
	int	controllo;

	c = 0;
	controllo = 1;
	while (str[c] != '\0' )
	{
		if (str[c] > 'Z' && str[c] < 'A')
		{
			controllo = 0;
			break ;
		}
		c++;
	}
	return (controllo);
}
