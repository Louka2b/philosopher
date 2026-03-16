/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:42:03 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/16 13:51:48 by ldeplace         ###   ########.fr       */
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
	if (pars(argv, &data) == 5)
		return (1);
	return (0);
}
