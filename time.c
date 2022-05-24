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

void	wait(long long time, t_data *data)
{
	long long	i;

	i = get_the_time();
	while (!data->dead)
	{
		if ((get_the_time() - i) >= time)
			break ;
	}
}
