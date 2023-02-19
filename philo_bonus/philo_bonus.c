/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 13:15:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

static void	ft_create_philos(t_program_data *data, pid_t *fork_ret)
{
	int				i;
	t_philo_info	*pi;

	data->philos = malloc(data->args.philo_nbr * sizeof(t_philo_info));
	if (! data->philos)
		return ;
	i = 0;
	while (i < data->args.philo_nbr && (*fork_ret > 0 || i == 0))
	{
		*fork_ret = fork();
		if (*fork_ret > 0)
			data->philos[i].pid = *fork_ret;
		i++;
	}
	if (*fork_ret == 0)
	{
		pi = &data->philos[i - 1];
		pi->id = i;
		pi->ch_status_ts = data->initial_ts;
		pi->eat_ts = data->initial_ts;
		pi->status = stat_sleeping;
		pi->eat_count = 0;
		pi->forks_taken = 0;
		ft_philo_behavior(data, i);
	}
}

static void	ft_destroy_philos(t_program_data *data)
{
	if (data->philos)
	{
		free (data->philos);
		data->philos = NULL;
	}
}

static void	ft_wait_for_philos(t_program_data *data, pid_t *fork_ret)
{
	pid_t			wp_ret;
	int				wp_status;
	int				i;

	(void)data;
	if (*fork_ret != 0)
	{
		wp_ret = waitpid(0, &wp_status, WCONTINUED);
		i = 0;
		while (i < data->args.philo_nbr)
		{
			kill(data->philos[i].pid, SIGKILL);
			i++;
		}
	}
}

static void	ft_deploy(t_program_data *data)
{
	pid_t	fork_ret;

	ft_get_timestamp(&data->initial_ts);
	ft_create_print_sem(data);
	ft_create_forks_sem(data);
	ft_create_philos(data, &fork_ret);
	if (fork_ret == 0)
		return ;
	ft_wait_for_philos(data, &fork_ret);
	ft_destroy_philos(data);
	ft_destroy_forks_sem(data);
	ft_destroy_print_sem(data);
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
