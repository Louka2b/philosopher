/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:42:03 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/13 21:43:46 by ldeplace         ###   ########.fr       */
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
	if (pars(argv, &data) == 5)
		return (1);
	data.start_time = timestamp_ms();
	return (0);
}