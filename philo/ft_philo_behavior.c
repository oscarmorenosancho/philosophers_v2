/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 11:33:28 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define CHECK_PERIOD	1000

void	*ft_philo_behavior(void *arg)
{
	t_philo_info	*pi;

	pi = arg;
	while (!ft_check_finish(pi) && pi->status != stat_dead)
	{
		if (pi->status == stat_sleeping)
			ft_philo_sleeps(pi);
		else if (pi->status == stat_thinking)
			ft_philo_thinks(pi);
		else if (pi->status == stat_eating)
			ft_philo_eats(pi);
	}
	return (NULL);
}

void	*ft_philo_dead(void *arg)
{
	t_philo_info	*pi;

	pi = arg;
	while (!ft_check_finish(pi))
	{
		ft_update_dead(pi);
		usleep (CHECK_PERIOD);
	}
	return (NULL);
}
