/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/25 09:04:48 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		buffer;

	if (argc != 5 && argc != 6)
		return (ft_write_error("Bad number of Args"));
	buffer = ft_init_all(&rules, argv);
	if (buffer)
		return (ft_error(buffer));
	if (ft_launcher(&rules))
		return (ft_write_error("Error creating threads"));
	return (0);
}
