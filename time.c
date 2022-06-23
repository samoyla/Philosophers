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

long int	get_time_ms(void)
{
	long long		ms;
	struct timeval	time;

	ms = 0;
	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("Error getimeofday\n", 2);
		return (EXIT_FAILURE);
	}
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

	i = get_time_ms();
	while (!check_data_death(data))
	{
		if (ft_timediff(get_time_ms(), i) >= time)
			break ;
		usleep(50);
	}
}
