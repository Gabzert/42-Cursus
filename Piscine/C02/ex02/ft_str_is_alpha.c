/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:31:49 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/10 16:35:40 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int	c;
	int	controllo;

	controllo = 1;
	c = 0;
	while (str[c] != '\0' )
	{
		if ((str[c] < 'a' && str[c] > 'z') && (str[c] > 'Z' && str[c] < 'A'))
		{
			controllo = 0;
			break ;
		}
		c++;
	}
	return (controllo);
}
