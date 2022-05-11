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

int	check_args(t_data *data, char **av)
{
	(void)av;
	if (data->nb_ph == 0 || data->nb_ph > 200)
	{
		ft_putstr_fd("the philo is non-existent or too much of them\n", 2);
		return (1);
	}
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
	{
		ft_putstr_fd("not enough time for existence\n", 2);
		return (1);
	}
	return (0);
}
