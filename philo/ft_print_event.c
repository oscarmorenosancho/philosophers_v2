/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:32:16 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 16:16:07 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_event(t_philo_info *pi, char *s)
{
	t_timestamp	ts;
	time_t		te;
	int			ml_ret;
	int			mu_ret;

	ml_ret = pthread_mutex_lock(pi->print_mutex);
	if (ft_check_not_finish(pi))
	{
		ft_get_timestamp(&ts);
		te = ft_time_diff(pi->initial_ts, &ts);
		printf("%lu %d %s at iter %d\n", te, pi->id, s, pi->eat_count);
	}
	mu_ret = pthread_mutex_unlock(pi->print_mutex);
}
