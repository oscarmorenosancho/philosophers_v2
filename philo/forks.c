/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:30:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/17 11:28:54 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_forks(t_program_data *data)
{
	int	i;

	if (data)
	{
		data->fork_mutexes = malloc(sizeof(pthread_mutex_t *) \
			* data->args.philo_nbr);
		data->forks = malloc(sizeof(int *) * data->args.philo_nbr);
		if (data->fork_mutexes)
		{
			memset(data->fork_mutexes, 0, \
				sizeof(pthread_mutex_t *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				data->fork_mutexes[i] = malloc(sizeof(pthread_mutex_t));
				if (data->fork_mutexes[i])
				{
					pthread_mutex_init(data->fork_mutexes[i], NULL);
				}
				i++;
			}
		}
		if (data->forks)
			memset(data->forks, 0, sizeof(int *) * data->args.philo_nbr);
	}
}

void	ft_delete_forks(t_program_data *data)
{
	int	i;

	if (data && data->fork_mutexes)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->fork_mutexes[i])
			{
				pthread_mutex_destroy(data->fork_mutexes[i]);
				free(data->fork_mutexes[i]);
			}
			i++;
		}
		free(data->fork_mutexes);
	}
	if (data->forks)
		free(data->forks);
}
