/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:10:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/22 11:09:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_init_philo(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;

	pi = &data->philo;
	pi->id = philo_id;
	pi->dead = 0;
	pi->ch_status_ts = data->initial_ts;
	pi->eat_ts = data->initial_ts;
	if (philo_id % 2)
		pi->status = stat_sleeping;
	else
		pi->status = stat_thinking;
	pi->eat_count = 0;
	pi->forks_taken = 0;
	pi->program_data = data;
	ft_create_status_sem(&data->philo);
	if (data->philo.status_sem_name)
	{
		pi->status_sem_name = ft_posfix_itoa("/philo_status_sem", philo_id);
		free(data->philo.status_sem_name);
		data->philo.status_sem_name = NULL;
	}
}

void	ft_create_philos(t_program_data *data, pid_t *fork_ret)
{
	int				i;

	data->philo_pids = malloc(sizeof(pid_t) * data->args.philo_nbr);
	if (!data->philo_pids)
		return ;
	i = 0;
	while (i < data->args.philo_nbr && (*fork_ret > 0 || i == 0))
	{
		*fork_ret = fork();
		if (*fork_ret > 0)
			data->philo_pids[i] = *fork_ret;
		i++;
	}
	if (*fork_ret == 0)
	{
		ft_init_philo(data, i);
		ft_create_check_dead(&data->philo);
		ft_philo_behavior(&data->philo);
	}
	else
		ft_create_done_thread(data);
}

void	ft_destroy_philos(t_program_data *data)
{
	if (! data)
		return ;
	if (data->philo_pids)
		free (data->philo_pids);
}

void	ft_kill_philos(t_program_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.philo_nbr)
	{
		kill(data->philo_pids[i], SIGKILL);
		i++;
	}
}

void	ft_wait_for_philos(t_program_data *data)
{
	pid_t	wp_ret;
	int		wp_status;
	int		i;

	i = 0;
	while (i < data->args.philo_nbr)
	{
		wp_ret = waitpid(data->philo_pids[i], &wp_status, WCONTINUED);
		i++;
	}
}
