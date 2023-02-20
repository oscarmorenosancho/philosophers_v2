/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:04:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 13:18:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_forks_sem(t_program_data *data)
{
	char	*err_msg;

	sem_unlink("/philo_forks_sem");
	data->sem_forks = sem_open("/philo_forks_sem", O_CREAT, \
		S_IRWXU, data->args.philo_nbr);
	if (data->sem_forks == SEM_FAILED)
	{
		data->sem_forks = NULL;
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "open forks semaphore failed\n"; 
		write(2, err_msg, ft_strlen(err_msg));
	}
}

void	ft_destroy_forks_sem(t_program_data *data)
{
	char	*err_msg;
	int		sc_ret;

	sc_ret = 0;
	if (data->sem_forks)
		sc_ret = sem_close(data->sem_forks);
	if (sc_ret != 0)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "close forks semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
	sem_unlink("/philo_forks_sem");
}

void	ft_take_forks(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;
	int				sw_ret;

	pi = &data->philo;
	while (pi->forks_taken < 2)
	{
		sw_ret = sem_wait(data->sem_forks);
		ft_print_event(data, "has taken a fork", philo_id);
		pi->forks_taken++;
	}
}

void	ft_release_forks(t_program_data *data, int philo_id)
{
	t_philo_info	*pi;

	(void)philo_id;
	pi = &data->philo;
	while (pi->forks_taken > 0)
	{
		sem_post(data->sem_forks);
		pi->forks_taken--;
	}
}
