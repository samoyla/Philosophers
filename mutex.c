/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:06:38 by masamoil          #+#    #+#             */
/*   Updated: 2022/06/08 14:52:59 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_data_death(t_data *data)
{
	pthread_mutex_lock(&(data->death_check));
	if (!data->dead)
	{
		pthread_mutex_unlock(&(data->death_check));
		return (0);
	}
	pthread_mutex_unlock(&(data->death_check));
	return (1);
}

int	check_ate(t_data *data)
{
	pthread_mutex_lock(&(data->meal_check));
	if (!data->if_all_ate)
	{
		pthread_mutex_unlock(&(data->meal_check));
		return (0);
	}
	pthread_mutex_unlock(&(data->meal_check));
	return (1);
}

int	get_ph_ate(t_data *data, t_philo *ph, int i)
{
	int	ret;

	pthread_mutex_lock(&(data->meal_check));
	ret = ph[i].ate;
	pthread_mutex_unlock(&(data->meal_check));
	return (ret);
}
