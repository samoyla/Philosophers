/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:17:49 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/30 22:06:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pickup_forks(t_data *data, t_philo *philo)
{	
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->l_fork]);
		message(philo->id, data, "\033[92mhas taken a fork\033[0m\n");
		pthread_mutex_lock(&data->forks[philo->r_fork]);
		message(philo->id, data, "\033[92mhas taken a fork\033[0m\n");
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->r_fork]);
		message(philo->id, data, "\033[92mhas taken a fork\033[0m\n");
		pthread_mutex_lock(&data->forks[philo->l_fork]);
		message(philo->id, data, "\033[92mhas taken a fork\033[0m\n");
	}
}

void	unleash_forks(t_data *data, t_philo *philo)
{	
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(data->forks[philo->l_fork]));
		pthread_mutex_unlock(&(data->forks[philo->r_fork]));
	}
	else
	{
		pthread_mutex_unlock(&(data->forks[philo->r_fork]));
		pthread_mutex_unlock(&(data->forks[philo->l_fork]));
	}
}

void	eat(t_data *data, t_philo *philo)
{
	if (philo->ate != data->meals)
	{
		pthread_mutex_lock(&(data->meal_check));
		philo->ate++;
		message(philo->id, data, "\033[33mis eating\033[0m\n");
		philo->t_last_meal = get_time_ms();
		pthread_mutex_unlock(&(data->meal_check));
	}
	wait(data->t_eat, data);
}

void	sleep_and_think(t_data *data, t_philo *ph)
{
	message(ph->id, data, "\033[96mis sleeping\033[0m\n");
	wait(data->t_sleep, data);
	message(ph->id, data, "\033[37mis thinking\033[0m\n");
}

int	check_data_death(t_data *data)
{
	pthread_mutex_lock(&(data->meal_check));
	if (!data->dead)
	{
		pthread_mutex_unlock(&(data->meal_check));
		return (0);
	}
	pthread_mutex_unlock(&(data->meal_check));
	return (1);
}

void	*routine(void *args)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (!check_data_death(data))
	{
		if (data->if_all_ate == 1)
			break ;
		pickup_forks(data, philo);
		eat(data, philo);
		unleash_forks(data, philo);
		sleep_and_think(data, philo);
	}
	return (0);
}
