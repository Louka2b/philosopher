/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:47:34 by louka             #+#    #+#             */
/*   Updated: 2026/03/20 13:55:06 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_philo *philo, t_data *data, int id)
{
	philo->id = id;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->data = data;
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		fill_philo(&data->philos[i], data, i + 1);
		i++;
	}
	assign_forks(data);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].last_meal = data->start_time;
		i++;
	}
}
