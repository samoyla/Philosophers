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

/*int	create_thread(t_data *data)
{

}

void	take_fork(t_data *data)
{
	pthread_mutex_lock();
}*/

void	*start_routine(void *args)
{
	t_data	*data;

	data = args;

	pthread_mutex_lock(&data->philo->l_fork);
	printf("philo %d is doing his routine\n", data->nb_ph);
	pthread_mutex_unlock(&data->philo->r_fork);
	return (0);
}

/*void eating()
{
	printf("");
}*/
