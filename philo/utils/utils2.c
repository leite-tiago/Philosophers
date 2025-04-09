/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:25:45 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/09 18:40:40 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	waiting_turn(t_philo *philo)
{
    if (philo->id % 2 == 0)
        usleep(philo->data->num_philos);
}

void	ft_usleep(long milliseconds)
{
	long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < milliseconds)
		usleep(10);
}
