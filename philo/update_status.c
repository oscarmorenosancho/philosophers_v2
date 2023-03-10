/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:11:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/22 17:07:33 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_update_done_status(t_philo_info *pi)
{
	pi->done = 1;
	if (pi->done_cntdwn && pi->done_cntdwn_mutex)
	{
		pthread_mutex_lock(pi->done_cntdwn_mutex);
		(*pi->done_cntdwn)--;
		pthread_mutex_unlock(pi->done_cntdwn_mutex);
	}
}

void	ft_update_dead(t_philo_info *pi)
{
	t_timestamp	ts;
	int			dead;
	time_t		et;
	int			ml_ret;
	int			mu_ret;

	ml_ret = pthread_mutex_lock(&pi->status_mutex);
	gettimeofday(&ts, NULL);
	et = ft_time_diff(&pi->eat_ts, &ts);
	dead = (et >= pi->args->time_to_die);
	if (dead && pi->status != stat_dead)
	{
		ft_print_event(pi, NULL, "died");
		if (pi->exit_flag)
			*(pi->exit_flag) = 1;
		pi->status = stat_dead;
		pi->ch_status_ts = ts;
	}
	mu_ret = pthread_mutex_unlock(&pi->status_mutex);
}

void	ft_update_status(t_philo_info *pi, t_philo_status new_status)
{
	t_timestamp	ts;
	int			ml_ret;
	int			mu_ret;

	ml_ret = pthread_mutex_lock(&pi->status_mutex);
	gettimeofday(&ts, NULL);
	pi->status = new_status;
	pi->ch_status_ts = ts;
	if (new_status == stat_eating)
	{
		pi->eat_ts = ts;
		pi->eat_count++;
	}
	mu_ret = pthread_mutex_unlock(&pi->status_mutex);
	if (new_status == stat_eating \
		&& pi->args->times_must_eat > 0 \
		&& pi->eat_count >= pi->args->times_must_eat)
		ft_update_done_status(pi);
}
