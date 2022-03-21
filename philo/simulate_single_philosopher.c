/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_single_philosopher.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:00:05 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 14:10:04 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

bool	eat(t_philosopher *philosopher)
{
	if (!print_log(philosopher, EATING))
	{
		put_forks(philosopher);
		return (false);
	}
	set_last_ate_at(philosopher, get_time_ms());
	sleep_in_ms(philosopher->args->eat_ms);
	philosopher->eat_count++;
	if (philosopher->args->has_limit
		&& !get_is_satisfied(&philosopher->is_satisfied)
		&& philosopher->eat_count == philosopher->args->eat_limit)
	{
		satisfied(&philosopher->is_satisfied);
		increment_eaten_count(&philosopher->vars->eaten_count);
	}
	return (put_forks(philosopher));
}

bool	go_to_sleep(t_philosopher *philosopher)
{
	if (!print_log(philosopher, SLEEPING))
		return (false);
	sleep_in_ms(philosopher->args->sleep_ms);
	return (true);
}

bool	think(t_philosopher *philosopher)
{
	if (!print_log(philosopher, THINKING))
		return (false);
	usleep(500);
	return (true);
}

void	*simulate_single_philosopher(void *philosopher_ptr)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)philosopher_ptr;
	if (philosopher->id % 2 == 0)
		usleep(1500);
	while (true)
	{
		if (get_is_satisfied(&philosopher->is_satisfied))
			return (NULL);
		if (!take_forks(philosopher))
			return (NULL);
		if (!eat(philosopher))
			return (NULL);
		if (!go_to_sleep(philosopher))
			return (NULL);
		if (!think(philosopher))
			return (NULL);
	}
	return (NULL);
}

void	*simulate_alone_philosopher(void *philosopher_ptr)
{
	t_philosopher	**philosopher;

	philosopher = (t_philosopher **)philosopher_ptr;
	print_log(philosopher[0], TAKING_FORK);
	sleep_in_ms(philosopher[0]->args->die_ms);
	usleep(MONITOR_TICK_US);
	return (NULL);
}
