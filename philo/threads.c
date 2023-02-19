/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:44:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/13 15:18:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_create_n_thread(t_program_data *data, int n)
{
	int				thc_ret;
	pthread_attr_t	attr;
	pthread_attr_t	*pattr;

	(void)attr;
	pattr = NULL;
	thc_ret = pthread_create(data->threads[n], pattr, \
		&ft_philo_behavior, data->philo[n]);
	//pthread_detach(*(data->threads[n]));
}

void	ft_create_threads(t_program_data *data)
{
	int	i;

	if (data)
	{
		data->threads = malloc(sizeof(pthread_t *) * data->args.philo_nbr);
		if (data->threads)
		{
			memset(data->threads, 0, \
				sizeof(pthread_t *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				data->threads[i] = malloc(sizeof(pthread_t));
				if (data->threads[i])
					ft_create_n_thread(data, i);
				i++;
			}
		}
	}	
}

void	ft_destroy_threads(t_program_data *data)
{
	int	i;

	if (data && data->threads)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->threads[i])
				free(data->threads[i]);
			i++;
		}
		free(data->threads);
	}
}

void	ft_join_threads(t_program_data *data)
{
	int	i;
	int	thj_ret;
	int	*retval;

	if (data && data->threads)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->threads[i])
			{
				thj_ret = pthread_join(*(data->threads[i]), (void **)&retval);
				if (thj_ret)
					;
			}
			i++;
		}
	}
}
