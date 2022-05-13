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

typedef struct s_philo
{
	int				id;
	struct s_data	*data;
	//pthread_mutex_t	fork;
	//pthread_t		philo_th;
}t_philo;

typedef struct s_data
{
	int		nb_ph;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		meals;
	t_philo	*philo;
}t_data;

typedef struct s_fork
{

}t_fork;

//functions:
void	ft_error(void);
int		init_data(t_data *data, char **av);
void	philo_usage(void);
//int		check_args(char **av);
int		check_args(int ac, char **av, t_data *data);
int		check_conditions(int ac, t_data *data);
void	*start_routine(void *args);
//utils
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);

#endif
