/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:58:54 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/26 11:27:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	int	ret;

	ret = ((c == ' ') || (c == '\n') || (c == '\t')
			|| (c == '\v') || (c == '\f') || (c == '\r'));
	return (ret);
}

static int	ft_isdigit(char c)
{
	int	ret;

	ret = (c >= '0' && c <= '9');
	return (ret);
}

static int	ft_take_sign(char **p)
{
	int	sign;

	sign = 1;
	if (**p == '+')
		(*p)++;
	else if (**p == '-')
	{
		(*p)++;
		sign = -1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		ret;
	int		s;
	char	*p;

	p = (char *)str;
	ret = 0;
	while (*p && ft_isspace(*p))
		p++;
	s = ft_take_sign(&p);
	while (*p && ft_isdigit(*p))
	{
		ret *= 10;
		ret += *p - '0';
		p++;
	}
	ret *= s;
	return (ret);
}
