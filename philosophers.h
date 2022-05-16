/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:07:59 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/09 18:08:03 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	struct s_data	*data;
	int				l_fork;
	int				r_fork;
	pthread_t		philo_th;
}t_philo;

typedef struct s_data
{
	int				nb_ph;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				meals;
	pthread_mutex_t	forks[250];
	t_philo			*philo;
}t_data;

//functions:
void	ft_error(void);
int		init_av(t_data *data, int ac, char **av);
int		init_mutex(t_data *data);
int		init_philo(t_data *data);
void	philo_usage(void);
int		check_args(int ac, char **av, t_data *data);
void	*start_routine(void *args);
//utils
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);

#endif
