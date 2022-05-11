/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:17:49 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/10 16:18:08 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*void	*eat(t_philo philo)
{	
	printf("");
}

void	*sleep(t_philo philo)
{

}

void	*think(t_philo philo)
{

}*/


void	*routine((void*)t_philo *philo)
{
	pthread_mutex_lock(&philo->forks);
	printf("philo %d is doing his routine\n", philo->data->nb_ph);
	pthread_mutex_unlock(&philo->forks);
}
