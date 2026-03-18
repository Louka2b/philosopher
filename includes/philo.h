/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:24:51 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/18 16:32:37 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	long			start_time;
	int				someone_dead;
	int				all_ate;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	struct s_philo	*philos;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;


int					pars(char **argv, t_data *data);
int					ft_atoi(const char *str);
int					check_number(char *str);
int					check_all_sign(int argc, char **argv);
int					init_forks(t_data *data);
int					check_all_number(int argc, char **argv);
int					check_sign(char *str);
int					init_global_mutexes(t_data *data);
int					init_all_mutexes(t_data *data);
long				elapsed_ms(long start_ms);
long				timestamp_ms(void);
void				assign_forks(t_data *data);
void				ft_usleep(long time);
void				destroy_global_mutexes(t_data *data);
void				destroy_forks(t_data *data);
void				fill_philo(t_philo *philo, t_data *data, int id);
void				init_data(t_data *data, char **argv, int argc);

#endif