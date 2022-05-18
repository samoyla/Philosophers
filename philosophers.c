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

/*int	main(int ac, char **av)
{
	t_data	data;

	if ((check_args(ac, av, &data)) == 1)
	{
		ft_putstr_fd("check your arguments\n", 2);
		return(EXIT_FAILURE);
	}
	printf("avant creat thread?\n");
	create_thread(&data);
	printf("there are %d philo\n", data.nb_ph);
	printf("time to die %d\n", data.t_death);
	printf("time to eat %d\n", data.t_eat);
	printf("time to sleep %d\n", data.t_sleep);
	printf("each philo ate %d times\n", data.meals);
	printf("right fork id: %d\n", data.philo->r_fork);
	printf("left fork id: %d\n", data.philo->l_fork);
	return (0);
}*/

pthread_mutex_t mutex;

void* routine() {
	int i = -1;
	while (++i < 3)
	{
		pthread_mutex_lock(&mutex);
		printf("y a un truc qui se passe\n");
		pthread_mutex_unlock(&mutex);
	}
	return(0);
}


int main(void) {
	pthread_t th[8];
	int i = -1;
	pthread_mutex_init(&mutex, NULL);
	while(++i < 3)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
			perror("Failed to create thread");
			return 1;
		}
		printf("Thread %d has started\n", i);
	}
	i  = -1;
	while (++i < 3) 
	{
		if (pthread_join(th[i], NULL) != 0) {
			return 2;
		}
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}