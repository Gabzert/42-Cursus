/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:47:17 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/23 17:24:32 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	table_init(t_data *table, char **argv)
{
	int	i;

	i = 0;
	table->philos = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argv[5])
		table->meals = ft_atoi(argv[5]);
	else
		table->meals = 0;
	table->forks = malloc (table->philos * sizeof(pthread_mutex_t));
	while (i < table->philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	*philo_brain(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->start_time = get_time();
	while (death_check(philo) == false && philo->eaten != philo->data->meals)
	{
		eat(philo);
		if (death_check(philo) == true)
			return (NULL);
		print(philo, "sta dormendo <zzzzzz>");
		usleep(philo->data->tts * 1000);
		if (death_check(philo) == true)
			return (NULL);
		print(philo, "sta filosofando <HMMMM>");
	}
	if (death_check(philo) == true)
		print(philo, "e' morto <ded>");
	return (NULL);
}

void	init_thread(t_philo *philos, t_data table)
{
	int	i;

	i = 0;
	while (i < table.philos)
	{
		philos[i].data = &table;
		philos[i].id = i;
		philos[i].eaten = 0;
		pthread_create(&philos[i].pt, NULL, philo_brain, (void *)&philos[i]);
		i++;
	}
	i = 0;
	while (i < table.philos)
	{
		pthread_join(philos[i].pt, NULL);
		i++;
	}	
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_data		table;

	if (argc < 5 || argc > 6)
	{
		printf("wrong number of arguments");
		return (0);
	}
	table_init(&table, argv);
	philos = malloc (table.philos * sizeof(t_philo));
	init_thread(philos, table);
	usleep(10000);
}
