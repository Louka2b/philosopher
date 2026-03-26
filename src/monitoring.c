/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:24:09 by louka             #+#    #+#             */
/*   Updated: 2026/03/26 14:26:23 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	simulation_stopped(t_data *data)
{
	int	stopped;

	stopped = 0;
	pthread_mutex_lock(&data->death_mutex);
	if (data->someone_dead || data->all_ate)
		stopped = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return (stopped);
}

static void	set_death_and_print(t_data *data, int philo_id)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->someone_dead || data->all_ate)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return ;
	}
	data->someone_dead = 1;
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d died\n", elapsed_ms(data->start_time), philo_id);
	pthread_mutex_unlock(&data->print_mutex);
	pthread_mutex_unlock(&data->death_mutex);
}

static int	monitor_one_philo(t_data *data, int i)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (data->must_eat_count >= 0
		&& data->philos[i].meals_eaten >= data->must_eat_count)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		return (0);
	}
	if (elapsed_ms(data->philos[i].last_meal) > data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		set_death_and_print(data, data->philos[i].id);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!simulation_stopped(data))
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (monitor_one_philo(data, i))
				return (NULL);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

