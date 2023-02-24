/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:02:34 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/23 14:54:11 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

bool	death_check(t_philo *philo)
{
	if (get_time() - philo->start_time >= philo->data->ttd)
	{
		printf("philo, e' morto <ded>");
		return (true);
	}
	else
		return (false);
}
