/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:23:58 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 18:54:13 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int			ft_atoi(const char *nptr);

bool	validate_int_range(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!ft_isdigit(nptr[i]))
		return (false);
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + sign * (nptr[i] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (false);
		i++;
	}
	if (nptr[i] != '\0')
		return (false);
	return (true);
}

bool	validate_chars(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] != '\0')
	{
		if (!ft_isdigit(nptr[i]) && nptr[i] != '-' && nptr[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (!validate_chars(nptr) || !validate_int_range(nptr))
		return (0);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = 10 * result + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
