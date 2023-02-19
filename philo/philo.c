/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/17 13:55:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_usage_help(void)
{
	char	*err_msg;

	err_msg = "Error\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "Usage: ./philo ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "<number_of_philosophers> <time_to_die> ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "<time_to_eat> <time_to_sleep> ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "[number_of_times_each_philosopher_must_eat]\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "All arguments must be positive\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "number_of_times_each_philosopher_must_eat can be 0\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "what will mean that the program only ends when one died\n";
	write(2, err_msg, ft_strlen(err_msg));
}

static void	ft_wait_for_ending(t_program_data *data)
{
	while (!data->exit_flag && data->done_cntdwn > 0)
		usleep(1000);
	if (data->done_cntdwn == 0)
		printf("DONE COUNTDOWN DETECTED, go and wait with join\n");
	if (data->exit_flag)
		printf("EXIT DETECTED, go and wait with join\n");
	ft_join_threads(data);
	printf("Joined all threads\n");
	usleep(1000);
}

static void	ft_deploy(t_program_data *data)
{
	ft_get_timestamp(&data->initial_ts);
	ft_init_print_mutex(data);
	ft_init_done_cntdwn_mutex(data);
	ft_init_forks(data);
	ft_init_philo(data);
	ft_create_threads(data);
	ft_wait_for_ending(data);
	ft_destroy_threads(data);
	ft_delete_philo(data);
	ft_delete_forks(data);
	ft_delete_done_cntdwn_mutex(data);
	ft_delete_print_mutex(data);
}

int	main(int argc, char **argv)
{
	t_program_data	data;

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
