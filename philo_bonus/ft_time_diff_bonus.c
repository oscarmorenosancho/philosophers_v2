/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_diff_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:03 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/30 16:01:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	ft_time_diff(t_timestamp *ref, t_timestamp *time)
{
	time_t	ret;
	time_t	sec;
	time_t	usec;

	ret = 0;
	if (ref && time)
	{
		sec = time->tv_sec - ref->tv_sec;
		if (time->tv_sec >= ref->tv_sec)
			usec = time->tv_usec - ref->tv_usec;
		else
		{
			usec = 1000000 - ref->tv_usec + time->tv_usec;
			sec++;
		}
		ret = sec * 1000 + usec / 1000;
	}
	return (ret);
}
