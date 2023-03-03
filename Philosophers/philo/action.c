/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:05:55 by gfantech          #+#    #+#             */
/*   Updated: 2023/03/03 15:43:13 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (death_check(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->forks[fork_finder(*philo, 1)]);
	pthread_mutex_lock(&philo->data->forks[fork_finder(*philo, 2)]);
	print (philo, "ha preso la sua forchetta <swing> ");
	print(philo, "ha preso un'altra forchetta <swing 2 the sequel>");
	print(philo, "sta mangiando <nom nom nom>");
	usleep(philo->data->tte * 1000);
	pthread_mutex_lock(&philo->data->meal);
	if (philo->data->meals > 0)
		philo->eaten++;
	pthread_mutex_unlock(&philo->data->meal);
	pthread_mutex_lock(&philo->data->time);
	philo->start_time = get_time();
	pthread_mutex_unlock(&philo->data->time);
	pthread_mutex_unlock(&philo->data->forks[fork_finder(*philo, 2)]);
	pthread_mutex_unlock(&philo->data->forks[fork_finder(*philo, 1)]);
}

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->printing);
	if (death_check(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->printing);
		return ;
	}
	printf("%lld : Philo %d %s\n", get_time(), philo->id, str);
	usleep(5);
	pthread_mutex_unlock(&philo->data->printing);
}