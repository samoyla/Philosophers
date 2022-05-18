/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:20:04 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/10 12:20:08 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}

void	philo_usage(void)
{
	ft_putstr_fd("philo usage is following:\n", 1);
	ft_putstr_fd("-number_of_philosopher\n", 1);
	ft_putstr_fd("-time_to_die\n", 1);
	ft_putstr_fd("-time_to_eat\n", 1);
	ft_putstr_fd("-time_to_sleep\n", 1);
}


int	check_args(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
	{
		philo_usage();
		return (1);
	}
	if (init_av(data, ac, av) == 1)
		ft_error();
	return (0);
}
