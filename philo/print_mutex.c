/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:52:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/30 13:07:29 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_print_mutex(t_program_data *data)
{
	if (data)
	{
		data->print_mutex = malloc(sizeof(pthread_mutex_t));
		if (data->print_mutex)
			pthread_mutex_init(data->print_mutex, NULL);
	}
}

void	ft_delete_print_mutex(t_program_data *data)
{
	if (data && data->print_mutex)
	{
		pthread_mutex_destroy(data->print_mutex);
		free(data->print_mutex);
	}
}
