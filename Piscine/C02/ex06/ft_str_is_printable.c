/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:30 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/10 18:13:54 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	c;
	int	controllo;

	c = 0;
	controllo = 1;
	while (str[c] != '\0' )
	{
		if (str[c] < 32)
			controllo = 0;
		c++;
	}
	return (controllo);
}
