/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:12 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/01 16:51:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_sleeps(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;

	pi = &data->philos[philo_id - 1];
	if (!ft_update_dead(data, &ts, philo_id))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= data->args.time_to_sleep)
		{
			ft_print_event(data, "is thinking", philo_id);
			pi->status = stat_thinking;
			pi->ch_status_ts = ts;
		}
	}
	return ;
}

void	ft_philo_thinks(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;
	int				sw_ret;	

	pi = &data->philos[philo_id - 1];
	if (!ft_update_dead(data, &ts, philo_id))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (pi->forks_taken == 0)
		{
			sw_ret = sem_wait(data->sem_forks);
			ft_print_event(data, "has taken a fork", philo_id);
			pi->forks_taken = 1;
		}
		if (!ft_update_dead(data, &ts, philo_id) \
				&& pi->forks_taken == 1 && data->args.philo_nbr > 1)
		{
			sem_wait(data->sem_forks);
			pi->forks_taken = 2;
			ft_print_event(data, "has taken a fork", philo_id);
			ft_print_event(data, "is eating", philo_id);
			pi->status = stat_eating;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			pi->eat_count++;
		}
	}
	return ;
}

static void	ft_release_forks(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;

	pi = &data->philos[philo_id - 1];
	if (pi->forks_taken == 2)
	{
		sem_post(data->sem_forks);
		pi->forks_taken = 1;
	}
	if (pi->forks_taken == 1 && data->args.philo_nbr > 1)
	{
		sem_post(data->sem_forks);
		pi->forks_taken = 0;
	}
}

void	ft_philo_eats(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;

	pi = &data->philos[philo_id - 1];
	if (!ft_update_dead(data, &ts, philo_id))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= data->args.time_to_eat)
		{
			ft_release_forks(data, philo_id);
			ft_print_event(data, "is sleeping", philo_id);
			pi->status = stat_sleeping;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			if (data->args.times_must_eat > 0 \
				&& pi->eat_count >= data->args.times_must_eat)
			{
				pi->status = stat_done;
			}
		}
	}
	else
		ft_release_forks(data, philo_id);
	return ;
}

void	ft_philo_behavior(t_program_data *data, int philo_id)
{
	void			*ret;
	t_philo_info	*pi;

	ret = NULL;
	pi = &data->philos[philo_id - 1];
	while (pi->status != stat_dead)
	{
		if (pi->status == stat_sleeping)
			ft_philo_sleeps(data, philo_id);
		else if (pi->status == stat_thinking)
			ft_philo_thinks(data, philo_id);
		else if (pi->status == stat_eating)
			ft_philo_eats(data, philo_id);
		else if (pi->status == stat_dead)
			return ;
		else if (pi->status != stat_done)
			pi->status = stat_dead;
		usleep(10);
	}
	return ;
}
