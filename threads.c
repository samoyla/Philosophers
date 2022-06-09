/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:15:17 by masamoil          #+#    #+#             */
/*   Updated: 2022/06/09 14:42:17 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_data *data)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = data->philo;
	data->first_time = get_time_ms();
	while (i < data->nb_ph)
	{
		ph[i].t_last_meal = get_time_ms();
		if (pthread_create(&(ph[i].philo_th), NULL, &routine, &(ph[i])) != 0)
			perror("failed to create a thread\n");
		i++;
	}
	death_check(data, ph);
	join_n_destroy(data, ph);
	return (0);
}

void	check_death_time(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < data->nb_ph && !(data->dead))
	{
		pthread_mutex_lock(&(data->meal_check));
		if (ft_timediff(get_time_ms(), ph[i].t_last_meal) > data->t_death)
		{
			pthread_mutex_lock(&(data->death_check));
			printf("%li ", get_time_ms() - data->first_time);
			printf("%i ", (i + 1));
			printf("\033[91mdied\033[0m\n");
			data->dead = 1;
			pthread_mutex_unlock(&(data->death_check));
		}
		pthread_mutex_unlock(&(data->meal_check));
		i++;
	}
}

void	death_check(t_data *data, t_philo *ph)
{
	int	i;

	while (check_ate(data) == 0)
	{
		check_death_time(data, ph);
		if (check_data_death(data) == 1)
			break ;
		i = 0;
		while (data->meals != -1 && i < data->nb_ph
			&& get_ph_ate(data, ph, i) >= data->meals)
			i++;
		if (i == data->nb_ph)
		{
			pthread_mutex_lock(&(data->meal_check));
			data->if_all_ate = 1;
			pthread_mutex_unlock(&(data->meal_check));
		}
	}
}

void	join_n_destroy(t_data *data, t_philo *ph)
{
	int			i;

	i = 0;
	while (i < data->nb_ph)
	{
		pthread_join(ph[i].philo_th, NULL);
		i++;
	}
	free(data->philo);
	i = 0;
	while (i < data->nb_ph)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&(data->message));
	pthread_mutex_destroy(&(data->meal_check));
	pthread_mutex_destroy(&(data->death_check));
}

void	message(int ph_id, t_data *data, char *s)
{
	pthread_mutex_lock(&(data->message));
	if (check_data_death(data) == 0)
	{
		printf("%li ", get_time_ms() - data->first_time);
		printf("%i ", (ph_id + 1));
		printf("%s", s);
	}
	pthread_mutex_unlock(&(data->message));
}
