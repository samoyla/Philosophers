/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:17:49 by masamoil          #+#    #+#             */
/*   Updated: 2022/06/24 13:46:41 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pickup_forks(t_data *data, t_philo *philo)
{	
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&data->forks[philo->r_fork]);
	else
		pthread_mutex_lock(&data->forks[philo->l_fork]);
	message(philo->id, data, "\033[92mhas taken a fork\033[0m\n");
	if (data->nb_ph > 1)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(&data->forks[philo->l_fork]);
		else
			pthread_mutex_lock(&data->forks[philo->r_fork]);
		message(philo->id, data, "\033[92mhas taken a fork\033[0m\n");
	}
	else
		wait(data->t_death, data);
}

void	unleash_forks(t_data *data, t_philo *philo)
{	
	if (philo->id % 2 == 0)
		pthread_mutex_unlock(&data->forks[philo->l_fork]);
	else
		pthread_mutex_unlock(&data->forks[philo->r_fork]);
	if (data->nb_ph > 1)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_unlock(&data->forks[philo->r_fork]);
		else
			pthread_mutex_unlock(&data->forks[philo->l_fork]);
	}
}

void	eat(t_data *data, t_philo *philo)
{
	if (philo->ate != data->meals)
	{
		pthread_mutex_lock(&(data->meal_check));
		philo->ate++;
		philo->t_last_meal = get_time_ms();
		pthread_mutex_unlock(&(data->meal_check));
		message(philo->id, data, "\033[33mis eating\033[0m\n");
	}
	wait(data->t_eat, data);
}

void	sleep_and_think(t_data *data, t_philo *ph)
{
	message(ph->id, data, "\033[96mis sleeping\033[0m\n");
	wait(data->t_sleep, data);
	message(ph->id, data, "\033[37mis thinking\033[0m\n");
	if (data->nb_ph % 2 == 1)
		wait(data->t_eat / 2, data);
}

void	*routine(void *args)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)args;
	data = philo->data;
	while (!check_data_death(data))
	{
		if (check_ate(data) == 1)
			break ;
		pickup_forks(data, philo);
		eat(data, philo);
		unleash_forks(data, philo);
		sleep_and_think(data, philo);
	}
	return (0);
}
