/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:49:42 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 14:41:35 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

bool	print_log(const t_philosopher *philosopher, t_state state)
{
	const int	id = philosopher->id;
	char		*state_str;

	if (state == EATING)
		state_str = "is \033[32meating\033[0m";
	else if (state == TAKING_FORK)
		state_str = "has \033[33mtaken a fork\033[0m";
	else if (state == THINKING)
		state_str = "is \033[34mthinking\033[0m";
	else if (state == SLEEPING)
		state_str = "is \033[35msleeping\033[0m";
	else if (state == STARVING)
		state_str = "is \033[31mdied\033[0m";
	pthread_mutex_lock(&philosopher->vars->liveness.mutex);
	if (!philosopher->vars->liveness.is_alive && state != STARVING)
	{
		pthread_mutex_unlock(&philosopher->vars->liveness.mutex);
		return (false);
	}
	printf("%lu %d %s\n", get_time_ms(), id, state_str);
	pthread_mutex_unlock(&philosopher->vars->liveness.mutex);
	return (true);
}
