/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:38:19 by akito             #+#    #+#             */
/*   Updated: 2022/03/27 11:38:46 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

bool	valid_args(t_args *args)
{
	if (!(0 < args->number_of_philosophers
			&& args->number_of_philosophers < MAX_PHILO))
		return (false);
	if (!(0 < args->die_ms && args->die_ms < MAX_MS))
		return (false);
	if (!(0 < args->eat_ms && args->eat_ms < MAX_MS))
		return (false);
	if (!(0 < args->sleep_ms && args->sleep_ms < MAX_MS))
		return (false);
	if (args->has_limit && !(0 < args->eat_limit && args->eat_limit < 10000LL))
		return (false);
	return (true);
}
