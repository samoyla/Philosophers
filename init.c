/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:38:34 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/10 17:38:51 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_data(t_data *data, char **av)
{
	int	i;

	i = -1;
	(void)av;
	//data->philo = malloc(sizeof(t_data) * data->nb_ph);
	while (--i >= 0)
	{
		data->philo[i].id = i;
	}
	return (0);
}
