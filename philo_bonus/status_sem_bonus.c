/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_sem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:00:12 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 18:50:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_status_sem(t_program_data *data)
{
	char	*err_msg;
	char	*id_str;

	if (!data->philo.status_sem_name)
		return ;
	id_str = ft_itoa(data->philo.id);
	sem_unlink(data->philo.status_sem_name);
	data->philo.sem_status = sem_open(data->philo.status_sem_name, O_CREAT, \
		S_IRWXU | S_IRWXG | S_IRWXO, 1);
	if (data->philo.sem_status == SEM_FAILED)
	{
		data->philo.sem_status = NULL;
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "open status semaphore failed\n"; 
		write(2, err_msg, ft_strlen(err_msg));
	}
}

void	ft_destroy_status_sem(t_program_data *data)
{
	char	*err_msg;
	int		sc_ret;

	if (!data->philo.status_sem_name)
		return ;
	sc_ret = 0;
	if (data->philo.sem_status)
		sc_ret = sem_close(data->philo.sem_status);
	if (sc_ret != 0)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "close status semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
	sem_unlink(data->philo.status_sem_name);
}
