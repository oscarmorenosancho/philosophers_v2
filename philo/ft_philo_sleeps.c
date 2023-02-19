/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleeps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:23:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/19 18:20:38 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_sleeps(t_philo_info *pi)
{
	t_timestamp	ts;
	time_t		et;

	if (ft_check_finish(pi))
		return ;
	gettimeofday(&ts, NULL);
	et = ft_time_diff(&pi->ch_status_ts, &ts);
	if (et < pi->args->time_to_sleep)
		usleep((pi->args->time_to_sleep - et) * 1000);
	gettimeofday(&ts, NULL);
	if (ft_check_finish(pi))
		return ;
	ft_update_status(pi, stat_thinking);
	ft_print_event(pi, &ts, "is thinking");
	return ;
}
