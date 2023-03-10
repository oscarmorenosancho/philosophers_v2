/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/23 16:25:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_print_usage_help(void)
{
	char	*err_msg;

	err_msg = "Error\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "Usage: ./philo_bonus ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "<number_of_philo> <time_to_die> ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "<time_to_eat> <time_to_sleep> ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "[number_of_times_each_philo_must_eat]\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "Time parameters will be expressed in miliseconds\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "All arguments must be positive\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "number_of_times_each_philo_must_eat can be 0\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "what will mean that the program only ends when one died\n";
	write(2, err_msg, ft_strlen(err_msg));
}

static void	ft_unblock_done_thread(t_program_data *data)
{
	data->exit_flag = 1;
	sem_post(data->sem_done);
}

static void	ft_deploy(t_program_data *data)
{
	pid_t	fork_ret;

	gettimeofday(&data->initial_ts, NULL);
	ft_create_exit_sem(data);
	ft_create_done_sem(data);
	ft_create_print_sem(data);
	ft_create_forks_sem(data);
	ft_create_philos(data, &fork_ret);
	if (fork_ret == 0)
	{
		ft_destroy_status_sem(&data->philo);
		return ;
	}
	sem_wait(data->sem_exit);
	ft_unblock_done_thread(data);
	ft_kill_philos(data);
	ft_wait_for_philos(data);
	ft_destroy_philos(data);
	ft_destroy_forks_sem(data);
	ft_destroy_print_sem(data);
	ft_destroy_done_sem(data);
	ft_destroy_exit_sem(data);
}

int	main(int argc, char **argv)
{
	t_program_data	data;
	pid_t			fork_ret;

	fork_ret = 0;
	memset(&data, 0, sizeof(t_program_data));
	if (argc == 5 || argc == 6)
	{
		if (ft_take_args(&data, argc, argv))
			ft_deploy(&data);
		else
			ft_print_usage_help();
	}
	else
		ft_print_usage_help();
	return (0);
}
