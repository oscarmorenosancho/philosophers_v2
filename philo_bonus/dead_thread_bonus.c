/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_thread_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:01:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/22 19:26:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#define CHECK_PERIOD	1000

static void	*ft_check_dead(void *arg)
{
	t_philo_info	*pi;
	int				id;
	t_timestamp		ts;
	int				dead;

	pi = arg;
	id = pi->id;
	dead = 0;
	while (! dead && !ft_check_finish(pi))
	{
		dead = ft_update_dead(pi, &ts);
		usleep(CHECK_PERIOD);
	}
	if (dead)
	{
		pi->program_data->exit_flag = 1;
		sem_post(pi->program_data->sem_exit);
	}
	return (NULL);
}

void	ft_create_check_dead(t_philo_info *pi)
{
	int				thc_ret;
	pthread_attr_t	*pattr;

	pattr = NULL;
	thc_ret = pthread_create(&pi->check_dead_thread, pattr, &ft_check_dead, pi);
	pthread_detach(pi->check_dead_thread);
}
