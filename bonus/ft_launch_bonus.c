/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/25 09:07:30 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

void	philo_eats(t_philosopher *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	sem_wait(rules->forks);
	ft_action_print(rules, philo->id, "has taken 1st fork");
	sem_wait(rules->forks);
	ft_action_print(rules, philo->id, "has taken 2nd fork");
	sem_wait(rules->meal_check);
	ft_action_print(rules, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	sem_post(rules->meal_check);
	ft_smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
	sem_post(rules->forks);
	sem_post(rules->forks);
}

void	*death_checker(void *void_philosopher)
{
	t_philosopher	*philo;
	t_rules			*r;

	philo = (t_philosopher *)void_philosopher;
	r = philo->rules;
	while (42)
	{
		sem_wait(r->meal_check);
		if (time_diff(philo->t_last_meal, timestamp()) > r->time_death)
		{
			ft_action_print(r, philo->id, "died");
			r->dieded = 1;
			sem_wait(r->writing);
			exit(1);
		}
		sem_post(r->meal_check);
		if (r->dieded)
			break ;
		usleep(1000);
		if (philo->x_ate >= r->nb_eat && r->nb_eat != -1)
			break ;
	}
	return (NULL);
}

void	p_process(void *void_phil)
{
	t_philosopher	*philo;
	t_rules			*rules;

	philo = (t_philosopher *)void_phil;
	rules = philo->rules;
	philo->t_last_meal = timestamp();
	pthread_create(&(philo->death_check), NULL, death_checker, void_phil);
	if (philo->id % 2)
		usleep(500);
	while (!(rules->dieded))
	{
		philo_eats(philo);
		if (philo->x_ate >= rules->nb_eat && rules->nb_eat != -1)
			break ;
		ft_action_print(rules, philo->id, "is sleeping");
		ft_smart_sleep(rules->time_sleep, rules);
		ft_action_print(rules, philo->id, "is thinking");
	}
	pthread_join(philo->death_check, NULL);
	if (rules->dieded)
		exit(1);
	exit(0);
}

void	ft_exit_launcher(t_rules *rules)
{
	int	i;
	int	ret;

	i = 0;
	while (i < rules->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < rules->nb_philo)
				kill(rules->philosophers[i].proc_id, 15);
			break ;
		}
		i++;
	}
	sem_close(rules->forks);
	sem_close(rules->writing);
	sem_close(rules->meal_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
}

int	ft_launch(t_rules *rules)
{
	int				i;
	t_philosopher	*phi;

	i = -1;
	phi = rules->philosophers;
	rules->first_timestamp = timestamp();
	while (++i < rules->nb_philo)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			p_process(&(phi[i]));
		usleep(100);
	}
	ft_exit_launcher(rules);
	return (0);
}
