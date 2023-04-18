/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:47:28 by gfantech          #+#    #+#             */
/*   Updated: 2023/03/31 12:42:44 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h> 
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_data {
	int			philos;
	int			ttd;
	int			tte;
	int			tts;
	int			meals;
	long long	sim_start;
	sem_t		*forks;
	sem_t		*dead;
	sem_t		*printing;
	sem_t		*eating;
}		t_data;

typedef struct s_philo {
	int			pid;
	int			id;
	t_data		*data;
	int			eaten;
	long long	start_time;
}		t_philo;

int			ft_atoi(const char *str);
long long	get_time(void);
void		*death_check(void *arg);
void		eat(t_philo *philo);
void		print(t_philo *philo, char *str);
int			finished(t_philo *philos, t_data *table);
int			is_ded(t_philo *philo, t_data *table);
void		philo_brain(t_philo *philo);
void		init_process(t_philo *philos, t_data table);
int			table_init(t_data *table, char **argv);
void		*destroy_all(void *arg);
void		close_sem(t_data *table);
#endif
