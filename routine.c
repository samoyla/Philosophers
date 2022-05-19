/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:17:49 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/13 09:55:27 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_data *data)
{
	int			i;
	t_philo		*ph;

	i = -1;
	ph = data->philo;
	// if (pthread_mutex_init(&(data->mutex), NULL) != 0)
	// {
	// 	perror("mutex failed\n");
	// 	exit(EXIT_FAILURE);
	// }
	//init_mutex(data);
	while (++i < data->nb_ph)
	{
		if (pthread_create(&(ph[i].philo_th), NULL, &routine, &(ph[i])) != 0)
			perror("failed to create thread\n");
		printf("Thread %d has started\n", i);
	}
	i = -1;
	while (++i < data->nb_ph)
	{
		if (pthread_join(ph[i].philo_th, NULL) != 0)
			return (1);
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&(data->mutex));
	return (0);
}

void	*routine(void *args)
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
}
