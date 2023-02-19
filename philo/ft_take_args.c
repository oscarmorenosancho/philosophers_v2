/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 11:38:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_args(t_program_data *data, int argc, char **argv)
{
	int	arg_ok;

	if (data)
	{
		arg_ok = ft_check_n_get_argument(argv[1], &data->args.philo_nbr);
		arg_ok &= ft_check_n_get_argument(argv[2], &data->args.time_to_die);
		arg_ok &= ft_check_n_get_argument(argv[3], &data->args.time_to_eat);
		arg_ok &= ft_check_n_get_argument(argv[4], &data->args.time_to_sleep);
		if (! arg_ok)
			return (0);
		data->args.times_must_eat = 0;
		if (argc == 6)
		{
			arg_ok = ft_check_n_get_argument(argv[5], \
						&data->args.times_must_eat);
			if (! arg_ok)
				return (0);
		}
	}
	return (data->args.philo_nbr > 0 && data->args.time_to_die > 0 \
		&& data->args.time_to_eat > 0 && data->args.time_to_sleep > 0 \
		&& data->args.times_must_eat >= 0);
}
