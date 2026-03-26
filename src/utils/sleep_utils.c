/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:11:10 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/26 14:41:45 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long	time_start;
	long	elapsed;
	long	remaining;

	time_start = timestamp_ms();
	while (1)
	{
		elapsed = elapsed_ms(time_start);
		if (elapsed >= time)
			break ;
		remaining = time - elapsed;
		if (remaining > 2)
			usleep((remaining - 1) * 1000);
		else
			usleep(100);
	}
}
