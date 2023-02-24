/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:05:55 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/23 09:38:24 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (death_check(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	printf("%ld : Philo %d sta mangiando <nom nom nom>\n", get_time(), philo->id);
	usleep(philo->data->tte * 1000);
	if (philo->data->meals > 0)
		philo->eaten++;
	philo->start_time = get_time();
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
}

void	print(t_philo *philo, char *str)
{
	if (death_check(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->printing);
	printf("%ld : Philo %d %s\n", get_time(), philo->id, str);
	usleep(5);
	pthread_mutex_unlock(&philo->data->printing);
}