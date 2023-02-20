/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:14:17 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 17:02:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_print_sem(t_program_data *data)
{
	char	*err_msg;

	sem_unlink("/philo_print_sem");
	data->sem_print = sem_open("/philo_print_sem", O_CREAT, \
		S_IRWXU | S_IRWXG | S_IRWXO, 1);
	if (data->sem_print == SEM_FAILED)
	{
		data->sem_print = NULL;
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "open print semaphore failed\n"; 
		write(2, err_msg, ft_strlen(err_msg));
	}
}

void	ft_destroy_print_sem(t_program_data *data)
{
	char	*err_msg;
	int		sc_ret;

	sc_ret = 0;
	if (data->sem_print)
		sc_ret = sem_close(data->sem_print);
	if (sc_ret != 0)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "close print semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
	sem_unlink("/philo_print_sem");
}

void	ft_create_exit_sem(t_program_data *data)
{
	char	*err_msg;

	sem_unlink("/philo_exit_sem");
	data->sem_exit = sem_open("/philo_exit_sem", O_CREAT, \
		S_IRWXU | S_IRWXG | S_IRWXO, 1);
	if (data->sem_exit == SEM_FAILED)
	{
		data->sem_exit = NULL;
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "open exit semaphore failed\n"; 
		write(2, err_msg, ft_strlen(err_msg));
	}
}

void	ft_destroy_exit_sem(t_program_data *data)
{
	char	*err_msg;
	int		sc_ret;

	sc_ret = 0;
	if (data->sem_exit)
		sc_ret = sem_close(data->sem_exit);
	if (sc_ret != 0)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "close exit semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
	sem_unlink("/philo_exit_sem");
}
