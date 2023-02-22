/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:29:51 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/22 16:59:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_create_n_dead_thread(t_program_data *data, int n)
{
	int				thc_ret;
	pthread_attr_t	attr;
	pthread_attr_t	*pattr;

	(void)attr;
	pattr = NULL;
	thc_ret = pthread_create(data->dead_threads[n], pattr, \
		&ft_philo_dead, data->philo[n]);
}

void	ft_create_dead_threads(t_program_data *data)
{
	int	i;

	if (data)
	{
		data->dead_threads = malloc(sizeof(pthread_t *) * data->args.philo_nbr);
		if (data->dead_threads)
		{
			memset(data->dead_threads, 0, \
				sizeof(pthread_t *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				data->dead_threads[i] = malloc(sizeof(pthread_t));
				if (data->dead_threads[i])
					ft_create_n_dead_thread(data, i);
				i++;
			}
		}
	}	
}

void	ft_destroy_dead_threads(t_program_data *data)
{
	int	i;

	if (data && data->dead_threads)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->dead_threads[i])
				free(data->dead_threads[i]);
			i++;
		}
		free(data->dead_threads);
	}
}

void	ft_join_dead_threads(t_program_data *data)
{
	int	i;
	int	thj_ret;
	int	*retval;

	if (data && data->dead_threads)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->dead_threads[i])
			{
				thj_ret = pthread_join(*(data->dead_threads[i]), \
							(void **)&retval);
				if (thj_ret)
					;
			}
			i++;
		}
	}
}
