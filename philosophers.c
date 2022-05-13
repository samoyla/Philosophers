/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:11:45 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/13 09:55:33 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"                      

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	//int		size;
	i = 0;
	if ((i = check_args(ac, av, &data)))
		ft_putstr_fd("check your arguments\n", 2);
	init_data(&data, av);
	printf("there are %d philo\n", data.nb_ph);
	printf("time to die %d\n", data.t_die);
	printf("time to eat %d\n", data.t_eat);
	printf("time to sleep %d\n", data.t_sleep);
	printf("philo's id is: %d\n", data.philo->id);
	return (0);
}
