/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/21 12:57:46 by omoreno-         ###   ########.fr       */
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
	int						id;
	int						exit_flag;
	char					*status_sem_name;
	sem_t					*sem_status;
	t_philo_status			status;
	int						eat_count;
	int						dead;
	int						forks_taken;
	t_timestamp				eat_ts;
	t_timestamp				ch_status_ts;
	pthread_t				check_dead_thread;
	struct s_program_data	*program_data;
}	t_philo_info;

typedef struct s_program_data
{	
	pid_t			*philo_pids;
	t_philo_args	args;
	sem_t			*sem_forks;
	sem_t			*sem_exit;
	sem_t			*sem_print;
	t_philo_info	philo;
	t_timestamp		initial_ts;
	int				exit_flag;
}	t_program_data;

int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int nbr);
char	*ft_posfix_itoa(const char *s, int nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_n_get_argument(const char *s, int *nbr);
void	ft_get_timestamp(t_timestamp *ts);
time_t	ft_time_diff(t_timestamp *ref, t_timestamp *time);
int		ft_take_args(t_program_data *data, int argc, char **argv);
void	ft_create_forks_sem(t_program_data *data);
void	ft_destroy_forks_sem(t_program_data *data);
void	ft_take_forks(t_philo_info *pi);
void	ft_release_forks(t_philo_info *pi);
void	ft_create_print_sem(t_program_data *data);
void	ft_destroy_print_sem(t_program_data *data);
void	ft_create_exit_sem(t_program_data *data);
void	ft_destroy_exit_sem(t_program_data *data);
void	ft_create_status_sem(t_philo_info *pi);
void	ft_destroy_status_sem(t_philo_info *pi);
void	ft_create_philos(t_program_data *data, pid_t *fork_ret);
void	ft_destroy_philos(t_program_data *data);
void	ft_kill_philos(t_program_data *data);
void	ft_wait_for_philos(t_program_data *data);
void	ft_create_check_dead(t_philo_info *pi);
int		ft_update_dead(t_philo_info *pi, t_timestamp *ts);
void	ft_philo_behavior(t_philo_info *pi);
void	ft_print_event(t_philo_info *pi, char *s);
int		ft_check_finish(t_philo_info *pi);

#endif