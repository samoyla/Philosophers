/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:11:45 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/09 18:11:47 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"                      

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo;
	int		i;
	int		size;
	size = data.nb_ph;
	pthread_t ph[size];

	if (ac < 5 || ac > 6)
		philo_usage();
	init_data(&data, av);
	if (check_args(&data, av) == 1)
		ft_putstr_fd("check your arguments\n", 2);
	pthread_mutex_init(&philo.forks, NULL);
	
	i = -1;
	while (++i < data.nb_ph)
	{
		if (pthread_create(ph + i, NULL, &routine, NULL) != 0)
			ft_error();
	}
	i = -1;
	while (++i < data.nb_ph)
	{
		if (pthread_join(ph[i], NULL) != 0)
			ft_error();
	}
	pthread_mutex_destroy(&philo.forks);

	/*printf("there are %d philo\n", data.nb_ph);
	printf("time to die %d\n", data.t_die);
	printf("time to eat %d\n", data.t_eat);
	printf("time to sleep %d\n", data.t_sleep);*/
	return (0);
}
