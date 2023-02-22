/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:39:59 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/22 15:41:28 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_finish(t_philo_info *pi)
{
	if (!pi || !pi->exit_flag || !pi->done_cntdwn)
		return (1);
	return (*(pi->exit_flag) || *(pi->done_cntdwn) == 0);
}
