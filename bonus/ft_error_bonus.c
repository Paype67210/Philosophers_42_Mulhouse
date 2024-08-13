/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/25 09:07:00 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

int	ft_write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	ft_error(int error)
{
	if (error == 1)
		return (ft_write_error("At least one wrong argument"));
	if (error == 2)
		return (ft_write_error("Fatal error when intializing semaphores"));
	return (1);
}
