/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:47:28 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/21 16:20:29 by gfantech         ###   ########.fr       */
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

typedef struct s_data {
	int				philos;
	int				ttd;
	int				tte;
	int				tts;
	int				meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
}		t_data;

typedef struct s_philo {
	pthread_t	pt;
	int			id;
	t_data		*data;
	int			eaten;
	int			start_time;
}		t_philo;

int		ft_atoi(const char *str);
int		ft_atoi_free(char *str);
int		get_time(void);
bool	death_check(t_philo *philo);
void	eat(t_philo *philo);
void	print(t_philo *philo, char *str);
#endif
