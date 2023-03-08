/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:57:28 by gfantech          #+#    #+#             */
/*   Updated: 2023/03/03 15:43:46 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	neg;

	num = 0;
	neg = 1;
	while (*str == 32 || *str == 9 || *str == '\r' || *str == '\v'
		|| *str == '\n' || *str == '\f')
	{
		str++;
	}
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		num = (num * 10) + ((*str) - '0');
		str++;
	}
	return (num * neg);
}

int	ft_atoi_free(char *str)
{
	int	n;

	n = ft_atoi(str);
	free(str);
	return (n);
}

void	destroy_mutex(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	pthread_mutex_destroy(&table->eating);
	pthread_mutex_destroy(&table->printing);
	pthread_mutex_destroy(&table->time);
}

int	fork_finder(t_philo philo, int fk)
{
	int	first_fork;
	int	second_fork;

	first_fork = philo.id;
	second_fork = (philo.id + 1) % philo.data->philos;
	if (fk == 1)
	{
		if (first_fork < second_fork)
			return (first_fork);
		else
			return (second_fork);
	}
	else if (fk == 2)
	{
		if (first_fork < second_fork)
			return (second_fork);
		else
			return (first_fork);
	}
	return (0);
}
