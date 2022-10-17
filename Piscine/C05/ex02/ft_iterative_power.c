/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:01:59 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 17:02:09 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	c;
	int	ris;

	c = 0;
	ris = 1;
	if (power < 0)
		return (0);
	while (c < power)
	{
		ris = ris * nb;
		c++;
	}
	return (ris);
}
