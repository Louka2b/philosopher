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

static void	routine_step_next(t_philo *philo, t_data *data)
{
	if (should_stop(data))
		return ;
	philo_sleep(philo, data);
	if (should_stop(data))
		return ;
	try_print(philo, data, "is thinking");
	if (data->nb_philo % 2 == 1)
		ft_usleep(data->time_to_eat / 2);
}

static void	routine_step(t_philo *philo, t_data *data)
{
	if (philo_is_full(philo, data))
	{
		ft_usleep(1);
		return ;
	}
	if (should_stop(data))
		return ;
	if (ft_take_forks(philo, data) != 1)
		return ;
	if (should_stop(data))
	{
		ft_drop_forks(philo, data);
		return ;
	}
	philo_eat(philo, data);
	ft_drop_forks(philo, data);
	if (philo_is_full(philo, data))
		return ;
	routine_step_next(philo, data);
}

void	philo_routine(t_philo *philo, t_data *data)
{
	wait_for_start(data);
	if (philo->id % 2 == 1)
	{
		if (data->nb_philo == 4)
			ft_usleep(1);
		else if (data->nb_philo % 2 == 0)
			ft_usleep(data->time_to_eat);
		else
			ft_usleep(data->time_to_eat / 2);
	}
	while (!should_stop(data))
		routine_step(philo, data);
}
