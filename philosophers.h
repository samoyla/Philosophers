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

typedef struct s_data
{
	int	nb_ph;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	meals;
}t_data;

typedef struct s_philo
{
	t_data			data;
	pthread_mutex_t	forks;
	pthread_t		philo;
}t_philo;

typedef struct s_fork
{

}t_fork;

//functions:
void	ft_error(void);
void	init_data(t_data *data, char **av);
void	philo_usage(void);
int		check_args(t_data *data, char **av);
void	*routine(t_philo *philo);
//utils
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
