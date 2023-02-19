/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/19 18:21:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eats(t_philo_info *pi)
{
	t_timestamp	ts;
	time_t		et;

	if (ft_check_finish(pi))
	{
		ft_release_forks(pi);
		return ;
	}	
	gettimeofday(&ts, NULL);
	et = ft_time_diff(&pi->ch_status_ts, &ts);
	if (et < pi->args->time_to_eat)
		usleep((pi->args->time_to_eat - et) * 1000);
	gettimeofday(&ts, NULL);
	ft_release_forks(pi);
	if (ft_check_finish(pi))
		return ;
	ft_update_status(pi, stat_sleeping);
	ft_print_event(pi, &ts, "is sleeping");
}
