/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thinks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/19 15:48:54 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_thinks(t_philo_info *pi)
{
	if (ft_check_finish(pi))
		return ;
	ft_take_left_fork(pi);
	if (ft_check_finish(pi))
	{
		ft_release_forks(pi);
		return ;
	}
	if (pi->args->philo_nbr > 1)
		ft_take_right_fork(pi);
	if (ft_check_finish(pi))
	{
		ft_release_forks(pi);
		return ;
	}
	ft_update_status(pi, stat_eating);
	ft_print_event(pi, "is eating");
}
