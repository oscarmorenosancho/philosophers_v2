/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_event_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:32:16 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/01 17:55:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_event(t_program_data *data, char *s, int philo_id)
{
	t_timestamp	ts;
	time_t		te;

	sem_wait(data->sem_print);
	ft_get_timestamp(&ts);
	te = ft_time_diff(&data->initial_ts, &ts);
	printf("%lu %d %s\n", te, philo_id, s);
	sem_post(data->sem_print);
}
