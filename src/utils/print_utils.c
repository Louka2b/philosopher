/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:41:41 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/20 17:49:29 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	try_print(t_philo *philo, char *msg)
{
	print_status(philo, msg);
}

int	print_status(t_philo *philo, char *msg)
{
	int	can;

	can = 0;
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->someone_dead == 0 && philo->data->all_ate == 0)
		can = 1;
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (!can)
		return (1);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", elapsed_ms(philo->data->start_time), philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (0);
}
