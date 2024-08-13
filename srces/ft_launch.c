/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/03/15 13:30:42 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_philo_eat(t_philosopher *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	ft_action_print(rules, philo->id, "has taken 1st fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	ft_action_print(rules, philo->id, "has taken 2nd forks");
	pthread_mutex_lock(&(rules->meal_check));
	ft_action_print(rules, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	ft_smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_rules			*rules;

	i = 0;
	philo = (t_philosopher *)void_philosopher;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(500);
	while (!(rules->dieded))
	{
		ft_philo_eat(philo);
		if (rules->all_ate)
			break ;
		ft_action_print(rules, philo->id, "is sleeping");
		ft_smart_sleep(rules->time_sleep, rules);
		ft_action_print(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	ft_exit_launcher(t_rules *rules, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	ft_death_checker(t_rules *r, t_philosopher *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->dieded))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->time_death)
			{
				ft_action_print(r, i, "died");
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

int	ft_launcher(t_rules *rules)
{
	int				i;
	t_philosopher	*philos;

	i = 0;
	philos = rules->philosophers;
	rules->first_timestamp = timestamp();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(philos[i].thread_id), \
			NULL, p_thread, &(philos[i])))
			return (1);
		philos[i].t_last_meal = timestamp();
		i++;
	}
	ft_death_checker(rules, rules->philosophers);
	ft_exit_launcher(rules, philos);
	return (0);
}
