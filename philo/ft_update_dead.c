/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_dead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:11:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 16:02:54 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_update_dead(t_philo_info *pi, t_timestamp *ts)
{
	int				dead;
	time_t			et;

	ft_get_timestamp(ts);
	et = ft_time_diff(&pi->eat_ts, ts);
	dead = (et >= pi->args->time_to_die);
	if (dead && pi->status != stat_dead)
	{
		ft_print_event(pi, "died");
		if (pi->exit_flag)
			*(pi->exit_flag) = 1;
		pi->status = stat_dead;
		pi->ch_status_ts = *ts;
	}
	return (dead);
}
