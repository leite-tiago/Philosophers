/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:08:11 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/09 18:51:46 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*check_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
	{
		handle_one_philo(philo);
		return (NULL);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_one(philo);
	waiting_turn(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->data->check_death);
		if (philo->data->stop == 1)
		{
			pthread_mutex_unlock(&philo->data->check_death);
			break ;
		}
		pthread_mutex_unlock(&philo->data->check_death);
		usleep(100);
		eat(philo);
		if (eat_enough(philo))
			return (NULL);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	*monitor_philos(void *arg)
{
	t_data	*d;

	d = (t_data *)arg;
	while (!d->stop)
	{
		check_death(d);
		pthread_mutex_lock(&d->check_death);
		if (d->stop == 1)
		{
			pthread_mutex_unlock(&d->check_death);
			return (NULL);
		}
		pthread_mutex_unlock(&d->check_death);
		check_all_eaten(d);
		usleep(100);
	}
	return (NULL);
}
