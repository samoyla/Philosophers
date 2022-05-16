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

int	init_philo(t_data *data)
{
	int	i;

	i = data->nb_ph;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->nb_ph;
	}
	return (0);
}

int	init_av(t_data *data, int ac, char **av)
{
	data->nb_ph = ft_atoi(av[1]);
	data->t_death = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
	if ((data->nb_ph) < 2 || (data->nb_ph) > 200)
		ft_putstr_fd("wrong number of philo\n", 2);
	else if ((data->t_death) < 60 || (data->t_death) > INT_MAX)
		ft_putstr_fd("wrong time to die\n", 2);
	else if ((data->t_eat) < 60 || (data->t_eat) > INT_MAX)
		ft_putstr_fd("wrong time to eat\n", 2);
	else if ((data->t_sleep) < 60 || (data->t_sleep) > INT_MAX)
		ft_putstr_fd("wrong time to sleep\n", 2);
	else if (ac == 6 && (data->meals) < 0)
		ft_putstr_fd("wrong number of meals\n", 2);
	return (1);
	//init_mutex;
	init_philo(data);
	return (0);
}
