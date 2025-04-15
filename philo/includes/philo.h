/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:29:18 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/15 12:59:35 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time;
	int				eat_count;
	struct s_data	*data;
}					t_philo;

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
}					t_data;

// utils
int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					ft_strcmp(const char *str1, const char *str2);

// utils2
long				get_time(void);
void				waiting_turn(t_philo *philo);
void				ft_usleep(long milliseconds);

// routine
void				*routine(void *arg);
void				*monitor_philos(void *arg);

// checks
void				check_death(t_data *d);
void				check_all_eaten(t_data *d);

// actions
void				eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				think(t_philo *philo);
int					eat_enough(t_philo *philo);
void				handle_one_philo(t_philo *philo);

// init
void				start_philo(t_data *d);
void				init_mutexes(t_data *d, int ac, char **av);
void				init_philos(t_data *d, int ac, char **av);

// free
void				ft_free(t_data *d);

// ft_print
void				ft_print(t_data *d, int id, char *act);

#endif
