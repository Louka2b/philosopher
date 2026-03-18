/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:46 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/16 13:54:57 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_global_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		return (1);
	}
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->death_mutex);
		return (1);
	}
	return (0);
}
