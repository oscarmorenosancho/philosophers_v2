/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:34:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/20 18:55:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

static int	ft_nbr_len(int nbr)
{
	int			len;
	long int	val;

	val = nbr;
	len = 0;
	if (val < 0)
		val = -val;
	while (val > 0)
	{
		val /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_digits(int val, char *buf, int len)
{
	int			i;

	if (val == 0)
		buf[0] = '0';
	else
	{
		i = len - 1;
		while (val > 0)
		{
			buf[i] = val % 10 + '0';
			val /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int nbr)
{
	char		*res;
	int			len;
	long int	val;

	len = ft_nbr_len(nbr);
	if (nbr <= 0)
		len++;
	res = malloc(len + 1);
	if (res)
	{
		res[len] = 0;
		val = nbr;
		if (nbr < 0)
		{
			res[0] = '-';
			val = -val;
		}
		ft_fill_digits(val, res, len);
	}
	return (res);
}

static void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_posfix_itoa(const char *s, int nbr)
{
	char		*res;
	int			len;
	long int	val;
	int			p_len;

	len = ft_nbr_len(nbr);
	p_len = ft_strlen(s);
	if (nbr <= 0)
		len++;
	res = malloc(len + p_len + 1);
	if (res)
	{
		ft_strcpy (res, s);
		res[len] = 0;
		val = nbr;
		if (nbr < 0)
		{
			res[p_len] = '-';
			val = -val;
		}
		ft_fill_digits(val, res, len);
	}
	return (res);
}
