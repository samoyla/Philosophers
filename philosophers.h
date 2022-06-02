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
# include <sys/time.h>
# include <time.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				ate;
	long int		t_last_meal;
	pthread_t		philo_th;
	struct s_data	*data;
}t_philo;

typedef struct s_data
{
	int				nb_ph;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				meals;
	int				if_all_ate;
	int				dead;
	long int		first_time;
	t_philo			philo[250];
	pthread_mutex_t	forks[250];
	pthread_mutex_t	message;
	pthread_mutex_t	meal_check;
}t_data;

//check-args
int			check_av_digit(char **av);
int			check_size_of_arg(char **av);
int			ft_check(char **av);
int			check_args(t_data *data, char **av);
void		philo_usage(void);
//init
void		init_philo(t_data *data);
int			init_mutex(t_data *data);
void		init_data(t_data *data);
void		init_data_av(t_data *data, char **av);
//threads
int			create_thread(t_data *data);
void		join_n_destroy(t_data *data, t_philo *ph);
//routine
void		*routine(void *args);
void		pickup_forks(t_data *data, t_philo *philo);
void		eat(t_data *data, t_philo *philo);
void		unleash_forks(t_data *data, t_philo *philo);
void		sleep_and_think(t_data *data, t_philo *ph);
void		message(int ph_id, t_data *data, char *s);
void		death_check(t_data *data, t_philo *ph);
//time fcts
long int	get_time_ms(void);
long long	ft_timediff(long long present, long long past);
void		wait(long long time, t_data *data);
//utils
int			ft_atoi(const char *nptr);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);

#endif
