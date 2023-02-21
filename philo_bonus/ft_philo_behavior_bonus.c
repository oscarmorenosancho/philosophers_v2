/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:12 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/21 13:01:11 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_sleeps(t_philo_info *pi)
{
	t_program_data	*pd;
	t_timestamp		ts;
	time_t			et;
	int				time_end;

	time_end = 0;
	pd = pi->program_data;
	while (!time_end)
	{	
		if (ft_check_finish(pi))
			return ;
		gettimeofday(&ts, NULL);
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		time_end = (et >= pd->args.time_to_sleep);
		if (et < pd->args.time_to_sleep)
			usleep((pd->args.time_to_sleep - et) * 800);
	}
	gettimeofday(&ts, NULL);
	if (ft_check_finish(pi))
		return ;
	et = ft_time_diff(&pi->ch_status_ts, &ts);
	if (et >= pd->args.time_to_sleep)
	{
		pi->status = stat_thinking;
		pi->ch_status_ts = ts;
		ft_print_event(pi, "is thinking");
	}
	return ;
}

void	ft_philo_thinks(t_philo_info *pi)
{
	t_program_data	*pd;
	t_timestamp		ts;
	time_t			et;

	pd = pi->program_data;
	if (!ft_update_dead(pi, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		ft_take_forks(pi);
		if (pi->forks_taken > 1)
		{
			ft_print_event(pi, "is eating");
			pi->status = stat_eating;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			pi->eat_count++;
		}
	}
	return ;
}

void	ft_philo_eats(t_philo_info	*pi)
{
	t_program_data	*pd;
	t_timestamp		ts;
	time_t			et;

	pd = pi->program_data;
	if (!ft_update_dead(pi, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= pd->args.time_to_eat)
		{
			ft_release_forks(pi);
			ft_print_event(pi, "is sleeping");
			pi->status = stat_sleeping;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			if (pd->args.times_must_eat > 0 \
				&& pi->eat_count >= pd->args.times_must_eat)
			{
				pi->status = stat_done;
			}
		}
	}
	else
		ft_release_forks(pi);
	return ;
}

void	ft_philo_behavior(t_philo_info *pi)
{
	void			*ret;

	ret = NULL;
	while (pi->status != stat_dead && !ft_check_finish(pi))
	{
		if (pi->status == stat_sleeping)
			ft_philo_sleeps(pi);
		else if (pi->status == stat_thinking)
			ft_philo_thinks(pi);
		else if (pi->status == stat_eating)
			ft_philo_eats(pi);
		else if (pi->status == stat_dead)
			return ;
		usleep(10);
	}
	return ;
}
