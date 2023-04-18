/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:02:34 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/03 09:56:08 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*death_check(void *arg)
{
	long long	death;
	long long	start_time;
	t_philo		*philo;

	philo = (t_philo *)arg;
	death = (long long) philo->data->ttd;
	while (philo->eaten != philo->data->meals)
	{
		start_time = philo->start_time;
		if (get_time() - start_time > death)
		{
			sem_wait(philo->data->printing);
			printf("%lld : Philo %d e' morto \033[0;31m<ded>\033[0m\n",
				get_time() - philo->data->sim_start, philo->id);
			sem_post(philo->data->dead);
			exit (0);
		}
	}
	return (NULL);
}

void	*destroy_all(void *arg)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)arg;
	sem_wait(philos->data->dead);
	while (i < philos->data->philos)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
	return (NULL);
}
