/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:22:36 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/04 10:22:38 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	dim;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	dim = (nmemb * size);
	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, dim);
	return (array);
}
