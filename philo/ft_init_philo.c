/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/17 11:57:00 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_swap_if_necessary(pthread_mutex_t **a, pthread_mutex_t **b,
				int **ia, int **ib)
{
	if (a && b && *a > *b)
	{
		ft_swap(a, b);
		ft_swap(ia, ib);
	}
}

static void	ft_init_philo_info(t_program_data *data, \
									int n, const t_timestamp *ts)
{
	memset(data->philo[n], 0, sizeof(t_philo_info));
	data->philo[n]->id = n + 1;
	data->philo[n]->args = &data->args;
	data->philo[n]->initial_ts = &data->initial_ts;
	data->philo[n]->eat_ts = *ts;
	data->philo[n]->eat_count = 0;
	data->philo[n]->done = 0;
	data->philo[n]->forks_taken = 0;
	data->philo[n]->ch_status_ts = *ts;
	data->philo[n]->exit_flag = &data->exit_flag;
	data->philo[n]->done_cntdwn = &data->done_cntdwn;
	if (n % 2)
		data->philo[n]->status = stat_thinking;
	else
		data->philo[n]->status = stat_sleeping;
}

static void	ft_init_n_philo(t_program_data *data, int n, const t_timestamp *ts)
{
	data->philo[n] = malloc(sizeof(t_philo_info));
	if (data->philo[n])
	{
		ft_init_philo_info(data, n, ts);
		data->philo[n]->left_fork_mutex = data->fork_mutexes[n];
		data->philo[n]->left_fork = &data->forks[n];
		data->philo[n]->right_fork_mutex = \
			data->fork_mutexes[(n + 1) % data->args.philo_nbr];
		data->philo[n]->right_fork = \
			&data->forks[(n + 1) % data->args.philo_nbr];
		ft_swap_if_necessary(&data->philo[n]->left_fork_mutex, \
								&data->philo[n]->right_fork_mutex, \
								&data->philo[n]->left_fork, \
								&data->philo[n]->right_fork);
		data->philo[n]->done_cntdwn_mutex = data->done_cntdwn_mutex;
		data->philo[n]->print_mutex = data->print_mutex;
	}
}

void	ft_init_philo(t_program_data *data)
{
	int				i;
	t_timestamp		ts;
	int				gtod_ret;

	if (data)
	{
		gtod_ret = gettimeofday(&ts, NULL);
		data->philo = malloc (sizeof(t_philo_info *) * data->args.philo_nbr);
		if (data->philo)
		{
			memset(data->philo, 0, \
				sizeof(t_philo_info *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				ft_init_n_philo(data, i, &ts);
				i++;
			}
		}
	}	
}

void	ft_delete_philo(t_program_data *data)
{
	int	i;

	if (data && data->philo)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->philo[i])
				free(data->philo[i]);
			i++;
		}
		free(data->philo);
	}	
}
