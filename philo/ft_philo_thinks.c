/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thinks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/17 13:27:31 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_thinks_with_no_fork(t_philo_info *pi)
{
	int	ml_ret;
	int	mu_ret;

	ml_ret = pthread_mutex_lock(pi->left_fork_mutex);
	if (*pi->left_fork == 0)
	{
		pi->forks_taken++;
		*pi->left_fork = 1;
		ft_print_event(pi, "has taken a fork: the first one");
	}
	mu_ret = pthread_mutex_unlock(pi->left_fork_mutex);
}

static void	ft_philo_thinks_with_one_fork(t_philo_info *pi)
{
	t_timestamp		ts;
	int				ml_ret;
	int				mu_ret;

	ml_ret = pthread_mutex_lock(pi->right_fork_mutex);
	if (*pi->right_fork == 0 && pi->args->philo_nbr > 1)
	{
		pi->forks_taken++;
		*pi->right_fork = 1;
		ft_print_event(pi, "has taken a fork: the second one");
	}
	mu_ret = pthread_mutex_unlock(pi->right_fork_mutex);
	if (pi->forks_taken > 1)
	{
		pi->status = stat_eating;
		ft_get_timestamp(&ts);
		pi->ch_status_ts = ts;
		pi->eat_ts = ts;
		ft_print_event(pi, "is eating");
		pi->eat_count++;
	}
}

void	ft_philo_thinks(t_philo_info *pi)
{
	t_timestamp		ts;

	if (!ft_update_dead(pi, &ts) && ft_check_not_finish(pi))
	{
		if (pi->forks_taken == 0 && ft_check_not_finish(pi))
			ft_philo_thinks_with_no_fork(pi);
		if (!ft_update_dead(pi, &ts) && \
				pi->left_fork != pi->right_fork \
				&& pi->forks_taken == 1 && ft_check_not_finish(pi))
			ft_philo_thinks_with_one_fork(pi);
	}
	else
		ft_release_forks(pi);
	usleep(50);
}
