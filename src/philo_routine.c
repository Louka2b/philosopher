/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <ldeplace@student.42.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:08:50 by louka             #+#    #+#             */
/*   Updated: 2026/03/20 17:25:13 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_is_full(t_philo *philo, t_data *data)
{
	int	full;

	if (data->must_eat_count < 0)
		return (0);
	pthread_mutex_lock(&data->meal_mutex);
	full = (philo->meals_eaten >= data->must_eat_count);
	pthread_mutex_unlock(&data->meal_mutex);
	return (full);
}

static int	should_stop(t_data *data)
{
	int	stop;

	stop = 0;
	pthread_mutex_lock(&data->death_mutex);
	if (data->someone_dead || data->all_ate)
		stop = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return (stop);
}

static int	check_self_death(t_philo *philo, t_data *data)
{
	if (philo_is_full(philo, data))
		return (0);
	pthread_mutex_lock(&data->meal_mutex);
	if (elapsed_ms(philo->last_meal) < data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_lock(&data->death_mutex);
	if (!data->someone_dead)
	{
		data->someone_dead = 1;
		pthread_mutex_unlock(&data->death_mutex);
		ft_usleep(1);
		printf("%ld %d died\n", elapsed_ms(data->start_time), philo->id);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}

static void	routine_step(t_philo *philo, t_data *data)
{
	if (philo_is_full(philo, data))
	{
		ft_usleep(1);
		return ;
	}
	if (ft_take_forks(philo, data) == 1)
	{
		philo_eat(philo, data);
		if (should_stop(data))
			return ;
		ft_drop_forks(philo, data);
		if (should_stop(data))
			return ;
		philo_sleep(philo, data);
	}
}

void	philo_routine(t_philo *philo, t_data *data)
{
	if (philo->id % 2 == 1)
		ft_usleep(1);
	while (!should_stop(data))
	{
		if (check_self_death(philo, data))
			break ;
		routine_step(philo, data);
	}
}
