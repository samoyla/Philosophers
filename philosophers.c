/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:11:45 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/30 22:09:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"                      

int	main(int ac, char **av)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	printf("%d\n", data.dead);
	if (ac < 5 || ac > 6)
	{
		philo_usage();
		return (EXIT_FAILURE);
	}
	if (check_args(&data, av) == 1)
	{
		ft_putstr_fd("check your arguments\n", 2);
		return (EXIT_FAILURE);
	}
	create_thread(&data);
	return (0);
}
