/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:49:15 by louka             #+#    #+#             */
/*   Updated: 2026/04/01 12:53:21 by louka            ###   ########.fr       */
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
