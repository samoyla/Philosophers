/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:39:01 by masamoil          #+#    #+#             */
/*   Updated: 2022/06/01 14:58:24 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_av_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && ft_isdigit(av[i][j]))
			j++;
		if (av[i][j])
			return (1);
		i++;
	}
	return (0);
}

int	check_size_of_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 10)
		{
			ft_putstr_fd("size of int is exceeded\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 10 && ft_strcmp(av[i], "2147483647") > 0)
		{
			ft_putstr_fd("size of int is exceeded\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(t_data *data, char **av)
{	
	if (check_size_of_arg(av) == 1 || ft_check(av) == 1)
		return (1);
	init_data_av(data, av);
	if (check_av_digit(av))
		return (1);
	if (data->nb_ph < 1)
	{
		ft_putstr_fd("there's no philo to feed\n", 2);
		return (1);
	}
	if (av[5])
	{
		data->meals = ft_atoi(av[5]);
		if (data->meals <= 0)
		{
			ft_putstr_fd("wrong number of meals\n", 2);
			return (1);
		}
	}
	else
		data->meals = -1;
	init_philo(data);
	if (init_mutex(data))
		return (1);
	return (0);
}
