/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_in_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:49:42 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 15:01:26 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	sleep_in_ms(size_t ms)
{
	size_t	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < ms)
		usleep(TICK_US);
	return ;
}

void	eating_ms(t_philosopher *philosopher, size_t ms)
{
	size_t	start_time;
	size_t	now;

	start_time = get_time_ms();
	now = get_time_ms();
	while (now - start_time < ms)
	{
		now = get_time_ms();
		set_last_ate_at(philosopher, now);
		usleep(TICK_US);
	}
	return ;
}
