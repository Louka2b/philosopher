/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:13:05 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/13 18:43:32 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

long	elapsed_ms(long start_ms)
{
	long	now_ms;

	now_ms = timestamp_ms();
	if (now_ms < 0)
		return (-1);
	return (now_ms - start_ms);
}