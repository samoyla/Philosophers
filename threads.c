/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:15:17 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/30 22:00:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_data *data)
{
	int		i;
	t_philo	*ph;

	i = -1;
	ph = data->philo;
	data->first_time = get_time_ms();
	while (++i < data->nb_ph)
	{
		ph[i].t_last_meal = get_time_ms();
		if (pthread_create(&(ph[i].philo_th), NULL, &routine, &(ph[i])) != 0)
			perror("failed to create thread\n");
	}
	death_check(data, ph);
	join_n_destroy(data, ph);
	return (0);
}

void	join_n_destroy(t_data *data, t_philo *ph)
{
	int			i;

	if (data->nb_ph == 1)
		i = 0;
	else
		i = -1;
	while (++i < data->nb_ph)
	{
		if (pthread_join(ph[i].philo_th, NULL) != 0)
		{
			ft_putstr_fd("pthread_join failed\n", 2);
			return ;
		}
	}
	i = -1;
	if (data->nb_ph != 1)
	{
		while (++i < data->nb_ph)
			pthread_mutex_destroy(&(data->forks[i]));
	}
	pthread_mutex_destroy(&(data->message));
}

void	death_check(t_data *data, t_philo *ph)
{
	int	i;

	while (data->if_all_ate == 0)
	{
		i = -1;
		while (++i < data->nb_ph && !(data->dead))
		{
			pthread_mutex_lock(&(data->meal_check));
			if (ft_timediff(get_time_ms(), ph[i].t_last_meal) > data->t_death)
			{
				message(i, data, "\033[91mdied\033[0m\n");
				data->dead = 1;
			}
			pthread_mutex_unlock(&(data->meal_check));
			usleep(100);
		}
		if (data->dead == 1)
			break ;
		i = 0;
		while (data->meals != -1 && i < data->nb_ph && ph[i].ate >= data->meals)
			i++;
		if (i == data->nb_ph)
			data->if_all_ate = 1;
	}
}

void	message(int ph_id, t_data *data, char *s)
{
	pthread_mutex_lock(&(data->message));
	if (data->dead == 0)
	{
		printf("%li ms ", get_time_ms() - data->first_time);
		printf("%i ", (ph_id + 1));
		printf("%s", s);
	}
	pthread_mutex_unlock(&(data->message));
}
