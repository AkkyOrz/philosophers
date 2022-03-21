/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_in_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:49:42 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 14:06:29 by akito            ###   ########.fr       */
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
