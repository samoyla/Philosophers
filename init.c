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

int	init_mutex(t_data *data)
{
	int	i;

	i = data->nb_ph;
	if (pthread_mutex_init(&data->message, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->meal_check, NULL) != 0)
		return (1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	return (0);
}

// int	init_philo(t_data *data)
// {
// 	int	i;

// 	i = data->nb_ph;
// 	while (--i >= 0)
// 	{
// 		data->philo[i].id = i;
// 		data->philo[i].l_fork = i;
// 		data->philo[i].r_fork = (i + 1) % data->nb_ph;
// 		//data->philo->data = data;
// 	}
// 	return (0);
// }

void	init_data(t_data *data)
{
	data->first_time = get_the_time();
	data->dead = 0;
	data->meals = 0;
	data->if_all_ate = 0;
	data->nb_ph = 0;
	data->t_death = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
}

int	init_av(t_data *data, char **av)
{
	init_data(data);
	data->nb_ph = ft_atoi(av[1]);
	data->t_death = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if ((data->nb_ph) > 200 || (data->t_death) < 60
		|| (data->t_eat) < 60 || (data->t_sleep) < 60)
	{
		ft_putstr_fd("at least one of the parameter is wrong\n", 2);
		return (1);
	}
	if (av[5])
	{
		data->meals = ft_atoi(av[5]);
		if (data->meals <= 0)
		{
			ft_putstr_fd("wrong number of meals\n", 2);
			return (1);
		}
	}
	else
		data->meals = -1;
	// init_philo(data);
	int i;
	i = data->nb_ph;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->nb_ph;
		data->philo[i].ate = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].data = data;
	}
	if (init_mutex(data))
		return (1);
	return (0);
}
