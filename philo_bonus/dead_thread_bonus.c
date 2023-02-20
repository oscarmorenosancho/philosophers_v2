/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_thread_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:01:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_dead(void *arg)
{
	t_program_data	*data;
	t_philo_info	*pi;
	int				id;
	int				dead;
	t_timestamp		ts;

	dead = 0;
	data = arg;
	pi = &data->philo;
	id = pi->id;
	while (! dead)
		dead = ft_update_dead(data, &ts, id);
	sem_post(data->sem_exit);
	return (NULL);
}

void	ft_create_check_dead(t_program_data *data)
{
	int				thc_ret;
	pthread_attr_t	attr;
	pthread_attr_t	*pattr;

	(void)attr;
	pattr = NULL;
	thc_ret = pthread_create(&data->philo.check_dead_thread, pattr, \
		&ft_check_dead, data);
	pthread_detach(data->philo.check_dead_thread);
}
