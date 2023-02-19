/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 13:20:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h> 
# include <sys/stat.h>
# include <signal.h>

typedef enum e_philo_status{
	stat_dead,
	stat_thinking,
	stat_eating,
	stat_sleeping,
	stat_done
}	t_philo_status;

typedef struct timeval	t_timestamp;

typedef struct s_philo_args
{
	int		philo_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_must_eat;
}	t_philo_args;

typedef struct s_philo_info
{
	int				id;
	pid_t			pid;
	t_philo_status	status;
	int				eat_count;
	int				forks_taken;
	t_timestamp		eat_ts;
	t_timestamp		ch_status_ts;
}	t_philo_info;

typedef struct s_program_data
{	
	t_philo_args	args;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	t_philo_info	*philos;
	t_timestamp		initial_ts;
}	t_program_data;

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_n_get_argument(const char *s, int *nbr);
void	ft_get_timestamp(t_timestamp *ts);
time_t	ft_time_diff(t_timestamp *ref, t_timestamp *time);
int		ft_take_args(t_program_data *data, int argc, char **argv);
void	ft_create_forks_sem(t_program_data *data);
void	ft_destroy_forks_sem(t_program_data *data);
void	ft_create_print_sem(t_program_data *data);
void	ft_destroy_print_sem(t_program_data *data);
int		ft_update_dead(t_program_data *data, t_timestamp *ts, int philo_id);
void	ft_philo_behavior(t_program_data *data, int philo_id);
void	ft_print_event(t_program_data *data, char *s, int philo_id);

#endif