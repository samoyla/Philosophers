/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:11:52 by masamoil          #+#    #+#             */
/*   Updated: 2022/06/09 15:06:17 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_data *data)
{	
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->nb_ph);
	if (!data->philo)
		return ;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_ph);
	if (!data->forks)
		return ;
	while (++i < data->nb_ph)
	{
		data->philo[i].id = i;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->nb_ph;
		data->philo[i].ate = 0;
		data->philo[i].t_last_meal = 0;
		data->philo[i].data = data;
	}
}

void	init_data_av(t_data *data, char **av)
{
	data->nb_ph = ft_atoi(av[1]);
	data->t_death = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = data->nb_ph;
	if (pthread_mutex_init(&(data->message), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->death_check), NULL) != 0)
		return (1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (1);
	}
	return (0);
}
