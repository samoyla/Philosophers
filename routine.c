/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:17:49 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/19 16:52:49 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_data *data)
{
	int			i;
	t_philo		*ph;

	i = -1;
	ph = data->philo;
	while (++i < data->nb_ph)
	{
		if (pthread_create(&(ph[i].philo_th), NULL, &routine, &(ph[i])) != 0)
			perror("failed to create thread\n");
		printf("Thread %d has started\n", i);
	}
	join_n_destroy(data);
	return (0);
}

void	join_n_destroy(t_data *data)
{
	int			i;
	t_philo		*ph;

	i = -1;
	ph = data->philo;
	while (++i < data->nb_ph)
	{
		pthread_join(ph[i].philo_th, NULL);
		printf("Thread %d has finished execution\n", i);
	}
	i = -1;
	while (++i < data->nb_ph)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->message));
}

void	pickup_forks(t_data *data, t_philo *philo)
{	
	printf("forks or not ?\n");
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(data->forks[philo->l_fork]));
		message(philo->id, data, "\033[92mhas taken a fork\033\n");
		printf("%d\n", philo->r_fork);
		pthread_mutex_lock(&(data->forks[philo->r_fork]));
		message(philo->id, data, "\033[92mhas taken a fork\033\n");
	}
	else
	{
		printf("and here ?\n");
		printf("%d\n", philo->r_fork);
		pthread_mutex_lock(&(data->forks[philo->r_fork]));
		message(philo->id, data, "\033[92mhas taken a fork\033\n");
		pthread_mutex_lock(&(data->forks[philo->l_fork]));
		message(philo->id, data, "\033[92mhas taken a fork\033\n");
	}
}

void	free_forks(t_data *data, t_philo *philo)
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

void	*routine(void *args)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)args;
	philo = data->philo;
	if (philo->id % 2 == 0)
		usleep(15000);
	pickup_forks(data, philo);
	free_forks(data, philo);
	return (0);
}
