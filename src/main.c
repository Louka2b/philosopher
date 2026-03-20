/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:42:03 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/20 17:33:38 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (write(1, "Error\nphilosophers need 4 or 5 args\n", 36), 1);
	if (check_all_sign(argc, argv) == -1)
		return (1);
	if (check_all_number(argc, argv) == -1)
		return (1);
	init_data(&data, argv, argc);
	if (init_all_mutexes(&data) != 0)
		return (write(1, "Error\nmutex init failed\n", 24), 1);
	if (pars(argv, &data) == 5)
		return (1);
	data.philos = malloc(sizeof (t_philo) * data.nb_philo);
	if (!data.philos)
		return (printf("malloc error\n"), 1);
	init_philos(&data);
	if (philo_start(&data) != 0)
		return (1);
	return (0);
}
