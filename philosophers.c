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
	t_data		data;
	int			i;

	i = -1;
	if ((check_args(ac, av, &data)) == 1)
	{
		ft_putstr_fd("check your arguments\n", 2);
		return (EXIT_FAILURE);
	}
	printf("right fork id: %d\n", data.philo->r_fork);
	printf("left fork id: %d\n", data.philo->l_fork);
	create_thread(&data);
	return (0);
}
