/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:38:34 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/10 17:38:51 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_data(t_data *data, char **av)
{
	int	i;

	i = -1;
	(void)av;
	//data->philo = malloc(sizeof(t_data) * data->nb_ph);
	while (--i >= 0)
	{
		data->philo[i].id = i;
	}
	return (0);
}

int	init_av(t_data *data, char **av)
{
	data->nb_ph = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
	return(0);
}
