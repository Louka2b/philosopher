/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:20:00 by louka             #+#    #+#             */
/*   Updated: 2026/03/24 14:27:11 by louka            ###   ########.fr       */
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

int	philo_start(t_data *data)
{
	int				i;
	t_routine_arg	*routine_arg;

	i = 0;
	while (i < data->nb_philo)
	{
		routine_arg = malloc(sizeof(t_routine_arg));
		if (!routine_arg)
			return (1);
		routine_arg->data = data;
		routine_arg->philo = &data->philos[i];
		if (create_thread(data, routine_arg, i) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
