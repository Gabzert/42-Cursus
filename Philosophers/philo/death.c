/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:02:34 by gfantech          #+#    #+#             */
/*   Updated: 2023/03/03 12:46:17 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

bool	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (philo->data->ded == 1)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (false);
	}
}

int	finished(t_philo *philos, t_data *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pthread_mutex_lock(&table->meal);
	while (i < table->philos)
	{
		if (philos[i].eaten == table->meals)
			j += 1;
		i++;
	}
	pthread_mutex_unlock(&table->meal);
	if (j == table->philos)
	{
		pthread_mutex_lock(&table->printing);
		printf("%lld Il conto grazie \n", get_time());
		pthread_mutex_unlock(&table->printing);
		return (1);
	}
	return (0);
}

int	is_ded(t_philo *philo, t_data *table)
{
	long long	death;
	long long	start_time;

	death = (long long) table->ttd;
	pthread_mutex_lock(&philo->data->time);
	start_time = philo->start_time;
	pthread_mutex_unlock(&philo->data->time);
	if (get_time() - start_time > death)
	{
		print(philo, "e' morto <ded>");
		pthread_mutex_lock(&table->dead);
		table->ded = 1;
		pthread_mutex_unlock(&table->dead);
		return (1);
	}
	else
		return (0);
}


