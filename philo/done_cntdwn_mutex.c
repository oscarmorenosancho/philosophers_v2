/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done_cntdwn_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:52:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/02 14:43:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_done_cntdwn_mutex(t_program_data *data)
{
	if (data)
	{
		data->done_cntdwn = data->args.philo_nbr;
		data->done_cntdwn_mutex = malloc(sizeof(pthread_mutex_t));
		if (data->done_cntdwn_mutex)
			pthread_mutex_init(data->done_cntdwn_mutex, NULL);
	}
}

void	ft_delete_done_cntdwn_mutex(t_program_data *data)
{
	if (data && data->done_cntdwn_mutex)
	{
		pthread_mutex_destroy(data->done_cntdwn_mutex);
		free(data->done_cntdwn_mutex);
	}
}
