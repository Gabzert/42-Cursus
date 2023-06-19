/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:47:17 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/18 15:50:40 by gfantech         ###   ########.fr       */
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

void	philo_brain(t_philo	*philo)
{
	pthread_t	pt;

	pthread_create (&pt, NULL, death_check, (void *)philo);
	if (philo->data->philos == 1)
		print (philo, "ha preso la sua forchetta \033[0;33m<swing>\033[0m");
	else
	{
		while (philo->eaten != philo->data->meals)
		{
			eat(philo);
			print(philo, "sta dormendo \033[0;34m<zzzzzzz>\033[0m");
			ft_usleep(philo->data->tts);
			print(philo, "sta filosofando  \033[0;32m<HMMMMMMM>\033[0m");
		}
	}
	pthread_join(pt, NULL);
	exit(0);
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
	init_process(philos, table);
	close_sem(&table);
	free(philos);
}
