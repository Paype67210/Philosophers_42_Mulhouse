/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:30:58 by gsmets            #+#    #+#             */
/*   Updated: 2024/04/25 09:03:54 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>

struct	s_rules;

typedef struct s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}		t_philosopher;

typedef struct s_rules
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philosopher		philosophers[250];
}		t_rules;

// ----- ft_error.c -----

int			ft_write_error(char *str);
int			ft_error(int error);

// ----- ft_init.c -----

int			ft_init_all(t_rules *rules, char **argv);

// ----- ft_utils.c -----

int			ft_atoi(const char *str);
void		ft_action_print(t_rules *rules, int id, char *string);
long long	timestamp(void);
long long	time_diff(long long past, long long pres);
void		ft_smart_sleep(long long time, t_rules *rules);

// ----- ft_launch.c -----

int			ft_launcher(t_rules *rules);
void		ft_exit_launcher(t_rules *rules, t_philosopher *philos);

#endif
