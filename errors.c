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
	init_av(data, av);
	if ((data->nb_ph) < 2 || (data->nb_ph) > 200)
		ft_putstr_fd("wrong number of philo\n", 2);
	else if ((data->t_die) < 60)
		ft_putstr_fd("no time to die\n", 2);
	else if ((data->t_eat) < 60)
		ft_putstr_fd("not enough time for eating\n", 2);
	else if ((data->t_sleep) < 60)
		ft_putstr_fd("not enough time for morfeus\n", 2);
	else if (ac == 6 && (data->meals) < 0)
		ft_putstr_fd("nothing to eat\n", 2);
	else
		return (init_data(data, av));
	return (1);
}
