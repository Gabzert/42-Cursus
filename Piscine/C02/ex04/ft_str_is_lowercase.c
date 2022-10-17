/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:59:20 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/10 17:59:41 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str)
{
	int	c;
	int	controllo;

	c = 0;
	controllo = 1;
	while (str[c] != '\0' )
	{
		if (str[c] > 'z' && str[c] < 'a')
		{
			controllo = 0;
			break ;
		}
		c++;
	}
	return (controllo);
}
