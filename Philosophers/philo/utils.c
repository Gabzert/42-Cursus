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

int	get_time(void)
{
	int				ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_usec;
	return (ms);
}

bool	death_check(t_philo *philo)
{
	int	now;

	now = get_time();
	if (now - philo->start_time >= philo->data->ttd)
	{
		print(philo, "e' morto <ded>");
		return (true);
	}
	else
		return (false);
}
