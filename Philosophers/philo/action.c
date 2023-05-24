/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:05:55 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/12 17:33:33 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (death_check(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	print (philo, "ha preso la sua forchetta \033[0;33m<swing>\033[0m");
	pthread_mutex_lock(&philo->data->forks[(philo->id
			+ philo->data->philos - 2) % philo->data->philos]);
	print(philo,
		"ha preso un'altra forchetta \033[0;33m<swing 2 the sequel>\033[0m");
	pthread_mutex_lock(&philo->data->time);
	philo->start_time = get_time();
	pthread_mutex_unlock(&philo->data->time);
	print(philo, "sta mangiando \033[0;35m<nom nom nom>\033[0m");
	usleep(philo->data->tte * 1000);
	pthread_mutex_lock(&philo->data->meal);
	if (philo->data->meals > 0)
		philo->eaten++;
	pthread_mutex_unlock(&philo->data->meal);
	pthread_mutex_unlock(&philo->data->forks[(philo->id
			+ philo->data->philos - 2) % philo->data->philos]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
}

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->printing);
	if (death_check(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->printing);
		return ;
	}
	printf("%lld : Philo %d %s    [%d]  \n", get_time() - philo->data->sim_start,
		philo->id, str, ((philo->id
				+ philo->data->philos - 2) % philo->data->philos));
	pthread_mutex_unlock(&philo->data->printing);
}
