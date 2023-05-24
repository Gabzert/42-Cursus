/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:05:55 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/11 14:24:57 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->data->eating);
	sem_wait(philo->data->forks);
	print(philo, "ha preso una forchetta \033[0;33m<swing>\033[0m");
	sem_wait(philo->data->forks);
	print(philo,
		"ha preso un'altra forchetta \033[0;33m<swing 2 the sequel>\033[0m");
	philo->start_time = get_time();
	print(philo, "sta mangiando \033[0;35m<nom nom nom>\033[0m");
	usleep(philo->data->tte * 1000);
	if (philo->data->meals > 0)
		philo->eaten++;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	sem_post(philo->data->eating);
}

void	print(t_philo *philo, char *str)
{
	sem_wait(philo->data->printing);
	printf("%lld : Philo %d %s\n", get_time() - philo->data->sim_start,
		philo->id, str);
	sem_post(philo->data->printing);
}
