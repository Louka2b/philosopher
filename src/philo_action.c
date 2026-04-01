/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:54:10 by louka             #+#    #+#             */
/*   Updated: 2026/04/01 12:54:19 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_all_ate_if_needed(t_data *data)
{
	int	i;

	if (data->must_eat_count < 0)
		return ;
	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philos[i].meals_eaten < data->must_eat_count)
			return ;
		i++;
	}
	pthread_mutex_lock(&data->death_mutex);
	data->all_ate = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

int	ft_take_forks(t_philo *philo, t_data *data)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		try_print(philo, data, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	fork_more(philo, data, first, second);
	return (1);
}

void	ft_drop_forks(t_philo *philo, t_data *data)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	(void)data;
}

void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal = timestamp_ms();
	pthread_mutex_unlock(&data->meal_mutex);
	try_print(philo, data, "is eating");
	ft_usleep(data->time_to_eat);
	pthread_mutex_lock(&data->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_lock(&data->meal_mutex);
	set_all_ate_if_needed(data);
	pthread_mutex_unlock(&data->meal_mutex);
}

void	philo_sleep(t_philo *philo, t_data *data)
{
	try_print(philo, data, "is sleeping");
	ft_usleep(data->time_to_sleep);
}
