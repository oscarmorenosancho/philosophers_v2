/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_get_arg_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:35:51 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/16 13:01:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_n_get_argument(const char *s, int *nbr)
{
	char	*clone;
	int		res;

	if (! s || ! s[0])
		return (0);
	if (s[0] == '+')
		s++;
	*nbr = ft_atoi(s);
	clone = ft_itoa(*nbr);
	res = ! ft_strncmp(s, clone, 20);
	free (clone);
	return (res);
}
