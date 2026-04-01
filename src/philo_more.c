/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:49:15 by louka             #+#    #+#             */
/*   Updated: 2026/04/01 13:16:04 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_more(t_philo *philo, t_data *data, pthread_mutex_t *first,
		pthread_mutex_t *second)

{
	pthread_mutex_lock(first);
	try_print(philo, data, "has taken a fork");
	pthread_mutex_lock(second);
	try_print(philo, data, "has taken a fork");
}

void	wait_for_start(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->start_mutex);
		if (data->start_simulation)
		{
			pthread_mutex_unlock(&data->start_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->start_mutex);
		ft_usleep(1);
	}
}
