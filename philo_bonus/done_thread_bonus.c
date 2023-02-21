/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done_thread_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:48:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/21 19:07:40 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_done(void *arg)
{
	t_program_data	*pd;
	int				done_philos;

	pd = arg;
	done_philos = 0;
	while (done_philos < pd->args.philo_nbr)
	{
		sem_wait(pd->sem_done);
		done_philos++;
		if (pd->exit_flag)
			return (NULL);
	}
	pd->exit_flag = 1;
	sem_post(pd->sem_exit);
	return (NULL);
}

void	ft_create_done_thread(t_program_data *data)
{
	int				thc_ret;
	pthread_attr_t	*pattr;

	pattr = NULL;
	thc_ret = pthread_create(&data->check_done_thread, pattr, \
								&ft_check_done, data);
	pthread_detach(data->check_done_thread);
}
