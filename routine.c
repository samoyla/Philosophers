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
	if (pthread_mutex_init(&(data->mutex), NULL) != 0)
	{
		perror("mutex failed\n");
		return (EXIT_FAILURE);
	}
	while (++i < data->nb_ph)
	{
		if (pthread_create(&(ph[i].philo_th), NULL, &routine, &(ph[i])) != 0)
			perror("failed to create thread\n");
		printf("Thread %d has started\n", i);
	}
	// i = -1;
	// while (++i < data->nb_ph)
	// {
	// 	printf("philo = %d\n", i);
	// 	if (pthread_join(ph[i].philo_th, NULL) != 0)
	// 		return (EXIT_FAILURE);
	// 	printf("Thread %d has finished execution\n", i);
	// }
	i = 0;
	while (i < data->nb_ph)
	{
		if (pthread_join(ph[i].philo_th, NULL) != 0)
		{
			printf("\033[91mJoin of thread failed\033\n");
		}
		i++;
	}
	pthread_mutex_destroy(&(data->mutex));
	return (0);
}

/*void	*routine(void *args)
{
	t_data	*data;
	int		i ;

	data = args;
	i = -1;
	while (++i < data->nb_ph)
	{
		pthread_mutex_lock(&(data->mutex));
		printf("y a un truc qui se passe\n");
		pthread_mutex_unlock(&(data->mutex));
	}
	return (0);
}*/

void	take_forks(t_data *data)
{	
	if (data->philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(data->forks[data->philo->l_fork]));
		printf("\033[92mhas taken a fork\033\n");
		pthread_mutex_lock(&(data->forks[data->philo->r_fork]));
		printf("\033[92mhas taken a fork\033\n");
	}
	else
	{
		pthread_mutex_lock(&(data->forks[data->philo->r_fork]));
		printf("\033[92mhas taken a fork\033\n");
		pthread_mutex_lock(&(data->forks[data->philo->l_fork]));
		printf("\033[92mhas taken a fork\033\n");
	}
}

void	free_forks(t_data *data)
{	
	if (data->philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(data->forks[data->philo->l_fork]));
		pthread_mutex_unlock(&(data->forks[data->philo->r_fork]));
	}
	else
	{
		pthread_mutex_unlock(&(data->forks[data->philo->r_fork]));
		pthread_mutex_unlock(&(data->forks[data->philo->l_fork]));
	}
}

void	*routine(void *args)
{
	t_data	*data;

	data = (t_data*)args;
	take_forks(data);
	free_forks(data);
	return (0);
}
