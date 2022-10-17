/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:04 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 11:46:28 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while (s1[c] == s2[c] && (s1[c] != '\0' || s2[c] != '\0'))
	{
		c++;
	}
	return (s1[c] - s2[c]);
}
