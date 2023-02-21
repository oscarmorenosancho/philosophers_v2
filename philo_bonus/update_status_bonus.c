/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_status_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:11:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/21 12:13:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*static void	ft_update_done_status(t_philo_info *pi)
{
	pi->done = 1;
	if (pi->done_cntdwn && pi->done_cntdwn_mutex)
	{
		pthread_mutex_lock(pi->done_cntdwn_mutex);
		(*pi->done_cntdwn)--;
		pthread_mutex_unlock(pi->done_cntdwn_mutex);
	}
}*/

int	ft_update_dead(t_philo_info *pi, t_timestamp *ts)
{
	t_program_data	*pd;
	int				dead;
	time_t			et;

	pd = pi->program_data;
	sem_wait(pi->sem_status);
	ft_get_timestamp(ts);
	et = ft_time_diff(&pi->eat_ts, ts);
	dead = (et >= pd->args.time_to_die);
	if (dead && pi->status != stat_dead)
	{
		ft_print_event(pi, "died");
		pi->status = stat_dead;
		pi->ch_status_ts = *ts;
	}
	sem_post(pi->sem_status);
	return (dead);
}

void	ft_update_status(t_philo_info *pi, t_philo_status new_status)
{
	t_program_data	*pd;
	t_timestamp		ts;

	pd = pi->program_data;
	sem_wait(pi->sem_status);
	gettimeofday(&ts, NULL);
	pi->status = new_status;
	pi->ch_status_ts = ts;
	if (new_status == stat_eating)
	{
		pi->eat_ts = ts;
		pi->eat_count++;
	}
	sem_post(pi->sem_status);
	/*if (new_status == stat_eating \
		&& pi->eat_count >= data->args.times_must_eat)
		ft_update_done_status(pi);*/
}
