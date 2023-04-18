/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:57:28 by gfantech          #+#    #+#             */
/*   Updated: 2023/03/31 12:43:11 by gfantech         ###   ########.fr       */
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

int	table_init(t_data *table, char **argv)
{
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
	sem_unlink("forks");
	sem_unlink("dead");
	sem_unlink("print");
	sem_unlink("eating");
	table->forks = sem_open("forks", O_CREAT, 0644, table->philos);
	table->dead = sem_open("dead", O_CREAT, 0644, 0);
	table->printing = sem_open("print", O_CREAT, 0644, 1);
	table->eating = sem_open("eating", O_CREAT, 0644, table->philos / 2);
	return (0);
}

void	close_sem(t_data *table)
{
	sem_close(table->dead);
	sem_close(table->eating);
	sem_close(table->forks);
	sem_close(table->printing);
}

void	init_process(t_philo *philos, t_data table)
{
	int			i;
	pthread_t	pt;

	i = 0;
	pthread_create (&pt, NULL, destroy_all, (void *)philos);
	table.sim_start = get_time();
	while (i < table.philos)
	{
		philos[i].data = &table;
		philos[i].id = i;
		philos[i].eaten = 0;
		philos[i].start_time = get_time();
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			philo_brain(&philos[i]);
		i++;
	}
	i = 0;
	while (i < table.philos)
	{
		waitpid(philos[i].pid, NULL, 0);
		i++;
	}
	sem_post(table.dead);
	pthread_join(pt, NULL);
}
