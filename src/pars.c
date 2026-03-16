/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:50:32 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/13 21:59:33 by ldeplace         ###   ########.fr       */
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

static void	init_philo_links(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = 0;
		i++;
	}
}


int	pars(char **argv, t_data *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->forks = NULL;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (write(1, "Error\nmalloc\n", 20),
			5);
	init_philo_links(data);
	if (init_forks(data))
		return (free(data->philos), write(1, "Error\nmutex init failed\n", 24),
			5);
	assign_forks(data);
	destroy_forks(data);
	free(data->philos);
	return (0);
}
