/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:47:17 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/18 15:05:12 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		printf("wrong number of arguments");
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			printf("value can't be 0 or negative");
			return (1);
		}
		i++;
	}
	return (0);
}

void	omniscience(t_philo *philos, t_data *table)
{
	int		i;

	while (finished(philos, table) == 0)
	{
		i = 0;
		while (i < table->philos)
		{
			if (is_ded(&philos[i], table) == 1)
				return ;
			i++;
		}
	}
}

void	*philo_brain(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep(((philo->id + 1) % 2) * 1000);
	if (philo->data->philos == 1)
		print (philo, "ha preso la sua forchetta \033[0;33m<swing>\033[0m");
	else
	{
		while (death_check(philo) == false
			&& philo->eaten != philo->data->meals)
		{
			eat(philo);
			if (death_check(philo) == true
				|| philo->eaten == philo->data->meals)
				pthread_exit(0);
			print(philo, "sta dormendo \033[0;36m<zzzzzz>\033[0m");
			ft_usleep(philo->data->tts);
			if (death_check(philo) == true
				|| philo->eaten == philo->data->meals)
				pthread_exit(0);
			print(philo, "sta filosofando \033[0;32m<HMMMM>\033[0m");
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_data		table;

	if (input_check(argc, argv) == 1)
		return (0);
	if (table_init(&table, argv) == 1)
		return (0);
	philos = malloc (table.philos * sizeof(t_philo));
	init_thread(philos, table);
	destroy_mutex(&table);
	free(philos);
}
