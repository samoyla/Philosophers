/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:38:12 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/23 16:38:14 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_the_time(void)
{
	long long		ms;
	struct timeval	time;

	ms = 0;
	if (gettimeofday(&time, NULL) == -1)
		ft_error();
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

long long	ft_timediff(long long present, long long past)
{
	int	i;

	i = present - past;
	return (i);
}

void	wait(long long time, t_data *data)
{
	long long	i;

	i = get_the_time();
	while (!(data->dead))
	{
		if (ft_timediff(get_the_time(), i) >= time)
			break ;
		usleep(50);
	}
}

// void	ft_usleep(long int time)
// {
// 	long int	start;

// 	start = get_the_time();
// 	while (ft_timediff(get_the_time(), start) < time)
// 		usleep(500);
// }
