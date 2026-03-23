/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:50:32 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/20 17:33:35 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_sign(int argc, char **argv)
{
	if (check_sign(argv[1]) == -1)
		return (printf("bad args entry\n"), -1);
	if (check_sign(argv[2]) == -1)
		return (printf("bad args entry\n"), -1);
	if (check_sign(argv[3]) == -1)
		return (printf("bad args entry\n"), -1);
	if (check_sign(argv[4]) == -1)
		return (printf("bad args entry\n"), -1);
	if (argc == 6)
	{
		if (check_sign(argv[5]) == -1)
			return (printf("bad args entry\n"), -1);
	}
	return (0);
}

int	check_all_number(int argc, char **argv)
{
	if (check_number(argv[1]) == -1)
		return (printf("bad args entry\n"), -1);
	if (check_number(argv[2]) == -1)
		return (printf("bad args entry\n"), -1);
	if (check_number(argv[3]) == -1)
		return (printf("bad args entry\n"), -1);
	if (check_number(argv[4]) == -1)
		return (printf("bad args entry\n"), -1);
	if (argc == 6)
	{
		if (check_number(argv[5]) == -1)
			return (printf("bad args entry\n"), -1);
	}
	return (0);
}

int	pars(char **argv, t_data *data)
{
	(void)argv;
	if (data->nb_philo <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (write(1, "Error\ninvalid args\n", 19), 5);
	if (data->must_eat_count == 0)
		return (write(1, "Error\ninvalid args\n", 19), 5);
	return (0);
}
