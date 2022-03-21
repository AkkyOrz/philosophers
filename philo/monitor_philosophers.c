/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:46:42 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 14:05:11 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

static bool	is_starved(t_philosopher *philo)
{
	size_t	die_ms;

	die_ms = philo->args->die_ms;
	if (!get_is_satisfied(&philo->is_satisfied)
		&& get_last_ate_at(philo) + die_ms < get_time_ms())
	{
		set_liveness(&philo->vars->liveness, false);
		print_log(philo, STARVING);
		return (true);
	}
	return (false);
}

void	*monitor_philosophers(void *philosophers_ptr)
{
	t_philosopher	**philosophers;
	int				i;
	int				num;

	i = 0;
	philosophers = (t_philosopher **)philosophers_ptr;
	num = philosophers[0]->args->number_of_philosophers;
	while (true)
	{
		i = 0;
		while (i < num)
		{
			if (is_all_philosopher_satisfied(&philosophers[0]->vars->eaten_count
					, num))
			{
				return (NULL);
			}
			if (is_starved(philosophers[i]))
				return (NULL);
			i++;
			usleep(MONITOR_TICK_US);
		}
	}
}
