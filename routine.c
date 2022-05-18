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
	printf("here\n");
	//t_philo		*philo;
	int			i;
	pthread_t	th[data->nb_ph];

	//philo = data->philo;
	i = 0;
	printf("i = %d\n", i);
	if (pthread_mutex_init(&data->mutex, NULL) != 0)
		perror("mutex failed\n");
	while (i < data->nb_ph)
	{
		if (pthread_create(th + 1, NULL, &routine, NULL) != 0)
			perror("failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < data->nb_ph)
	{
		if (pthread_join(th[i], NULL))
			return (1);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
	return (0);
}

void	*routine(void *args)
{
	t_data	*data;

	data = args;

	pthread_mutex_lock(&data->mutex);
	printf("philo %d is doing his routine\n", data->nb_ph);
	pthread_mutex_unlock(&data->mutex);
	return (0);
}
