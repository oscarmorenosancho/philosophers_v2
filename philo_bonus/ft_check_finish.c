/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:32:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/21 15:08:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_finish(t_philo_info *pi)
{
	t_program_data	*pd;

	pd = pi->program_data;
	return (pi->exit_flag || pi->dead || pd->exit_flag);
}
