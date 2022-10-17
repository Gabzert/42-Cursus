/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:09:08 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/11 12:09:27 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	c;
	int				d;

	c = 0;
	d = 0;
	while (dest[d] != '\0')
	{
		d++;
	}
	while (src[c] != '\0' && c < nb)
	{
		dest[d] = src[c];
		c++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
