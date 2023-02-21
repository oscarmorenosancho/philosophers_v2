/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:12 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/21 16:19:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_timer(t_philo_info *pi, int preset)
{
	t_timestamp		ts;
	time_t			et;
	int				time_end;

	time_end = 0;
	while (!time_end)
	{	
		if (ft_check_finish(pi))
			return ;
		gettimeofday(&ts, NULL);
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		time_end = (et >= preset);
		if (et < preset)
			usleep((preset - et) * 800);
	}	
}

void	ft_philo_sleeps(t_philo_info *pi)
{
	t_program_data	*pd;

	pd = pi->program_data;
	ft_timer(pi, pd->args.time_to_sleep);
	if (ft_check_finish(pi))
		return ;
	ft_update_status(pi, stat_thinking);
	ft_print_event(pi, "is thinking");
	return ;
}

void	ft_philo_thinks(t_philo_info *pi)
{
	t_program_data	*pd;

	pd = pi->program_data;
	if (ft_check_finish(pi))
		return ;
	ft_take_forks(pi);
	if (ft_check_finish(pi))
		ft_release_forks(pi);
	if (pi->forks_taken > 1)
	{
		ft_update_status(pi, stat_eating);
		ft_print_event(pi, "is eating");
	}
	return ;
}

void	ft_philo_eats(t_philo_info	*pi)
{
	t_program_data	*pd;

	pd = pi->program_data;
	ft_timer(pi, pd->args.time_to_eat);
	ft_release_forks(pi);
	if (ft_check_finish(pi))
		return ;
	ft_update_status(pi, stat_sleeping);
	ft_print_event(pi, "is sleeping");
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
	}
	return ;
}
