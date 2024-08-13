/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/03/15 13:27:35 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_atoi(const char *str)
{
	long long int	buffer;
	int				i;
	int				sign;

	buffer = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		buffer = (buffer * 10) + (str[i++] - '0');
	return (sign * buffer);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_smart_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = timestamp();
	while (!(rules->dieded))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	ft_action_print(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->dieded))
	{
		printf("%lli\t", timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}
