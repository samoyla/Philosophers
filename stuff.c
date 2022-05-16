/*pthread_mutex_init(&philo.fork, NULL);
	size = data.nb_ph;
	pthread_t ph[size];
	i = -1;
	while (++i < data.nb_ph)
	{
		if (pthread_create(ph + i, NULL, &start_routine, NULL) != 0)
			ft_error();
	}
	i = -1;
	while (++i < data.nb_ph)
	{
		if (pthread_join(ph[i], NULL) != 0)
			ft_error();
	}
	pthread_mutex_destroy(&philo.fork);*/
