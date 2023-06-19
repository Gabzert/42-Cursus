/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:57:28 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/18 14:34:17 by gfantech         ###   ########.fr       */
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

	first_fork = (philo.id - 1);
	second_fork = (philo.id + philo.data->philos - 2) % philo.data->philos;
	if (fk == 1)
	{
		if (first_fork > second_fork)
			return (first_fork);
		else
			return (second_fork);
	}
	else if (fk == 2)
	{
		if (first_fork > second_fork)
			return (second_fork);
		else
			return (first_fork);
	}
	return (0);
}

int	table_init(t_data *table, char **argv)
{
	int	i;

	i = -1;
	table->ded = 0;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (0);
	table->philos = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argv[5] && ft_atoi(argv[5]) != 0)
		table->meals = ft_atoi(argv[5]);
	else
		table->meals = -1;
	table->forks = malloc (table->philos * sizeof(pthread_mutex_t));
	while (++i < table->philos)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->printing, NULL);
	pthread_mutex_init(&table->eating, NULL);
	pthread_mutex_init(&table->time, NULL);
	pthread_mutex_init(&table->dead, NULL);
	pthread_mutex_init(&table->meal, NULL);
	return (0);
}

void	init_thread(t_philo *philos, t_data table)
{
	int	i;

	i = 0;
	table.sim_start = get_time();
	while (i < table.philos)
	{
		philos[i].data = &table;
		philos[i].id = i + 1;
		philos[i].eaten = 0;
		philos[i].start_time = get_time();
		if (pthread_create(&philos[i].pt, NULL,
				philo_brain, (void *)&philos[i]) != 0)
			perror("oh no");
		i++;
	}
	i = 0;
	omniscience(philos, &table);
	while (i < table.philos)
	{
		pthread_join(philos[i].pt, NULL);
		i++;
	}
}
