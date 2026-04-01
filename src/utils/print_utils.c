/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:41:41 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/26 13:21:25 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	try_print(t_philo *philo, t_data *data, char *msg)
{
	int	i;

	i = 0;
	while (print_status(philo, msg) != 0 && data->all_ate == 0
		&& data->someone_dead == 0 && i != 10)
	{
		ft_usleep(1);
		i++;
	}
}

int	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->someone_dead == 1 || philo->data->all_ate == 1)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->data->someone_dead == 1 || philo->data->all_ate == 1)
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	printf("%ld %d %s\n", elapsed_ms(philo->data->start_time), philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}
