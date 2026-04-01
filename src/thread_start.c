/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:20:00 by louka             #+#    #+#             */
/*   Updated: 2026/04/01 13:11:47 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_thread_init(void *arg)
{
	t_routine_arg	*routine_arg;
	t_data			*data;
	t_philo			*philo;

	routine_arg = (t_routine_arg *)arg;
	data = routine_arg->data;
	philo = routine_arg->philo;
	free(routine_arg);
	(void)data;
	(void)philo;
	philo_routine(philo, data);
	return (NULL);
}

static int	create_thread(t_data *data, t_routine_arg *routine_arg, int i)
{
	if (pthread_create(&data->philos[i].thread, NULL, philo_thread_init,
			routine_arg) != 0)
	{
		free(routine_arg);
		return (1);
	}
	return (0);
}

static int	stop_and_join_created_threads(t_data *data, int created_count)
{
	int	j;

	pthread_mutex_lock(&data->start_mutex);
	data->start_simulation = 1;
	pthread_mutex_unlock(&data->start_mutex);
	pthread_mutex_lock(&data->death_mutex);
	data->someone_dead = 1;
	pthread_mutex_unlock(&data->death_mutex);
	j = 0;
	while (j < created_count)
	{
		pthread_join(data->philos[j].thread, NULL);
		j++;
	}
	write(2, "Error\npthread_create failed\n", 28);
	return (1);
}

static int	philo_start_more(t_data *data, t_routine_arg *routine_arg, int i)
{
	i = 0;
	while (i < data->nb_philo)
	{
		routine_arg = malloc(sizeof(t_routine_arg));
		if (!routine_arg)
			return (1);
		routine_arg->data = data;
		routine_arg->philo = &data->philos[i];
		if (create_thread(data, routine_arg, i) != 0)
			return (stop_and_join_created_threads(data, i));
		i++;
	}
	data->start_time = timestamp_ms();
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].last_meal = data->start_time;
		i++;
	}
	return (0);
}

int	philo_start(t_data *data)
{
	int				i;
	pthread_t		monitor;
	t_routine_arg	*routine_arg;

	i = 0;
	routine_arg = NULL;
	if (philo_start_more(data, routine_arg, i) == 1)
		return (1);
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
		return (stop_and_join_created_threads(data, data->nb_philo));
	pthread_mutex_lock(&data->start_mutex);
	data->start_simulation = 1;
	pthread_mutex_unlock(&data->start_mutex);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
