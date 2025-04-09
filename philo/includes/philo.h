/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:29:18 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/09 18:50:54 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time;
	int				eat_count;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				stop;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	t_philo			*philos;
	pthread_mutex_t	lock;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	check_death;
	int				odd;
}				t_data;

/* ----- utils.c -----*/
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(const char *str1, const char *str2);

/* ----- utils2.c -----*/
long	get_time(void);
void	waiting_turn(t_philo *philo);
void	ft_usleep(long milliseconds);

/* ----- routine.c -----*/
void	*routine(void *arg);
void	*monitor_philos(void *arg);

/* ----- checks.c -----*/
void	check_death(t_data *d);
void	check_all_eaten(t_data *d);

/* ----- actions.c -----*/
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
int		eat_enough(t_philo *philo);
void	handle_one_philo(t_philo *philo);

/* ----- init.c -----*/
void	start_philo(t_data *d);
void	init_mutexes(t_data *d, int ac, char **av);
void	init_philos(t_data *d, int ac, char **av);

/* ----- free.c -----*/
void	ft_free(t_data *d);

/* ----- ft_print.c -----*/
void	ft_print(t_data *d, int id, char *act);

#endif
