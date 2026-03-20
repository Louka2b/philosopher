/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:08:50 by louka             #+#    #+#             */
/*   Updated: 2026/03/20 14:27:58 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo, t_data *data)
{
	(void)data;
	try_print(philo, "test");
	ft_usleep(700);
	try_print(philo, "test2");
}