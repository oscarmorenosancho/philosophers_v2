/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:39:59 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 13:48:23 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_not_finish(t_philo_info *pi)
{
	return (pi && pi->exit_flag && !*(pi->exit_flag) && \
				pi->done_cntdwn && *pi->done_cntdwn > 0);
}
