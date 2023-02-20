/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:12 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 16:57:59 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_sleeps(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;
	int				time_end;

	time_end = 0;
	pi = &data->philo;
	while (!time_end)
	{	
		if (ft_check_finish(data))
			return ;
		gettimeofday(&ts, NULL);
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		time_end = (et >= data->args.time_to_sleep);
		if (et < data->args.time_to_sleep)
			usleep((data->args.time_to_sleep - et) * 800);
	}
	gettimeofday(&ts, NULL);
	if (ft_check_finish(data))
		return ;
	et = ft_time_diff(&pi->ch_status_ts, &ts);
	if (et >= data->args.time_to_sleep)
	{
		pi->status = stat_thinking;
		pi->ch_status_ts = ts;
		ft_print_event(data, "is thinking", philo_id);
	}
	return ;
}

void	ft_philo_thinks(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;

	pi = &data->philo;
	if (!ft_update_dead(data, &ts, philo_id))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		ft_take_forks(data, philo_id);
		if (pi->forks_taken > 1)
		{
			ft_print_event(data, "is eating", philo_id);
			pi->status = stat_eating;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			pi->eat_count++;
		}
	}
	return ;
}

void	ft_philo_eats(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;

	pi = &data->philo;
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
	pi = &data->philo;
	while (pi->status != stat_dead && !ft_check_finish(data))
	{
		if (pi->status == stat_sleeping)
			ft_philo_sleeps(data, philo_id);
		else if (pi->status == stat_thinking)
			ft_philo_thinks(data, philo_id);
		else if (pi->status == stat_eating)
			ft_philo_eats(data, philo_id);
		else if (pi->status == stat_dead)
			return ;
		usleep(10);
	}
	return ;
}
