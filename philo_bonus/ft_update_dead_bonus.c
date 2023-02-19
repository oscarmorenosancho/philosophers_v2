/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_dead_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:11:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/01 15:46:55 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_update_dead(t_program_data *data, t_timestamp *ts, int philo_id)
{
	t_philo_info	*pi;
	int				dead;
	time_t			et;

	pi = &data->philos[philo_id - 1];
	ft_get_timestamp(ts);
	et = ft_time_diff(&pi->eat_ts, ts);
	dead = (et >= data->args.time_to_die);
	if (dead && pi->status != stat_dead)
	{
		ft_print_event(data, "died", philo_id);
		pi->status = stat_dead;
		pi->ch_status_ts = *ts;
	}
	return (dead);
}
