/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_event_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:32:16 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/23 16:26:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_event(t_philo_info *pi, char *s)
{
	t_timestamp		ts;
	time_t			te;
	t_program_data	*pd;

	pd = pi->program_data;
	if (ft_check_finish(pi))
		return ;
	sem_wait(pd->sem_print);
	if (!ft_check_finish(pi))
	{
		gettimeofday(&ts, NULL);
		te = ft_time_diff(&pd->initial_ts, &ts);
		printf("%lu %d %s\n", te, pi->id, s);
	}
	sem_post(pd->sem_print);
}
