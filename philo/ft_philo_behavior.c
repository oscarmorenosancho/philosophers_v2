/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/19 19:53:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define CHECK_PERIOD	5000

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
	//ft_release_forks(pi);
	//ft_print_event(pi, "has finished the thread");
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

void	ft_update_dead_loop(t_program_data *data)
{
	int			i;

	i = 0;
	while (!data->exit_flag && data->done_cntdwn > 0)
	{
		ft_update_dead(data->philo[i]);
		i++;
		i %= data->args.philo_nbr;
	}
	usleep (CHECK_PERIOD);
}
