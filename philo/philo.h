/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/19 18:44:28 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h> 
# include <sys/time.h>

typedef enum e_philo_status{
	stat_dead,
	stat_thinking,
	stat_eating,
	stat_sleeping
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
	int				*exit_flag;
	t_philo_status	status;
	int				eat_count;
	int				done;
	int				*done_cntdwn;
	int				forks_taken;
	t_timestamp		eat_ts;
	t_timestamp		ch_status_ts;
	t_timestamp		*initial_ts;
	t_philo_args	*args;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	pthread_mutex_t	*done_cntdwn_mutex;
	pthread_mutex_t	*print_mutex;
}	t_philo_info;

typedef struct s_program_data
{	
	int				exit_flag;
	int				done_cntdwn;
	t_philo_args	args;
	pthread_t		**threads;
	pthread_t		**dead_threads;
	int				*forks;
	pthread_mutex_t	**fork_mutexes;
	pthread_mutex_t	*done_cntdwn_mutex;
	pthread_mutex_t	*print_mutex;
	t_philo_info	**philo;
	t_timestamp		initial_ts;
}	t_program_data;

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_swap(void *a, void *b);
time_t	ft_time_diff(t_timestamp *ref, t_timestamp *time);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_n_get_argument(const char *s, int *nbr);
int		ft_take_args(t_program_data *data, int argc, char **argv);
void	ft_init_print_mutex(t_program_data *data);
void	ft_delete_print_mutex(t_program_data *data);
void	ft_init_done_cntdwn_mutex(t_program_data *data);
void	ft_delete_done_cntdwn_mutex(t_program_data *data);
void	ft_init_forks(t_program_data *data);
void	ft_delete_forks(t_program_data *data);
void	ft_take_left_fork(t_philo_info *pi);
void	ft_take_right_fork(t_philo_info *pi);
void	ft_init_philo(t_program_data *data);
void	ft_delete_philo(t_program_data *data);
int		ft_check_finish(t_philo_info *pi);
void	ft_update_dead(t_philo_info *pi);
void	ft_update_dead_loop(t_program_data *data);
void	ft_update_status(t_philo_info *pi, t_philo_status new_status);
void	ft_philo_sleeps(t_philo_info *pi);
void	ft_philo_thinks(t_philo_info *pi);
void	ft_release_forks(t_philo_info *pi);
void	ft_philo_eats(t_philo_info *pi);
void	*ft_philo_behavior(void *arg);
void	*ft_philo_dead(void *arg);
void	ft_create_threads(t_program_data *data);
void	ft_join_threads(t_program_data *data);
void	ft_destroy_threads(t_program_data *data);
void	ft_create_dead_threads(t_program_data *data);
void	ft_join_dead_threads(t_program_data *data);
void	ft_destroy_dead_threads(t_program_data *data);
void	ft_print_event(t_philo_info *pi, t_timestamp *ts, char *s);
#endif