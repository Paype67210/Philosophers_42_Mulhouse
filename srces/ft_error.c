/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/03/14 08:33:43 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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
		return (ft_write_error("Wrong value of argument"));
	if (error == 2)
		return (ft_write_error("Error intializing mutex"));
	return (1);
}
