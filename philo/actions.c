/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:20:22 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/09 18:38:20 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
	}
	ft_print(philo->data, philo->id, "has taken a fork");
	ft_print(philo->data, philo->id, "is eating");
	pthread_mutex_lock(&philo->data->check_meal);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->check_meal);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->data->check_meal);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->check_meal);
}

void	philo_sleep(t_philo *philo)
{
	ft_print(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	ft_print(philo->data, philo->id, "is thinking");
}

int	eat_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_meal);
	if (philo->data->must_eat_count > 0
		&& philo->eat_count >= philo->data->must_eat_count)
	{
		pthread_mutex_unlock(&philo->data->check_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->check_meal);
	return (0);
}

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo->data, philo->id, "has taken a fork");
	ft_usleep(philo->data->time_to_die);
	ft_print(philo->data, philo->id, "died");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->data->check_death);
	philo->data->stop = 1;
	pthread_mutex_unlock(&philo->data->check_death);
}
