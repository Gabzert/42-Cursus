/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:12:07 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 16:12:19 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	if (nb == 1 || nb == 0)
		return (1);
	return (0);
}
