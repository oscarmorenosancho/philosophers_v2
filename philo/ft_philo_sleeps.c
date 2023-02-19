/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleeps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:23:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/17 13:34:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_sleeps(t_philo_info *pi)
{
	t_timestamp		ts;
	time_t			et;

	if (!ft_update_dead(pi, &ts) && ft_check_not_finish(pi))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= pi->args->time_to_sleep && ft_check_not_finish(pi))
		{
			ft_print_event(pi, "is thinking");
			pi->status = stat_thinking;
			pi->ch_status_ts = ts;
		}
	}
	return ;
}
