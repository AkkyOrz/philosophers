#include "helper.h"
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

bool	monitor_starving(t_var *var)
{
	const t_args		*args;

	args = var->args;
	while (true)
	{
		pthread_mutex_lock(var->philosopher_mutex);
			if (var->philosopher->last_ate_at + (size_t)args->die_ms < get_time_ms())
			{
				print_log(var->philosopher, STARVING);
				return (false);
			}
		pthread_mutex_unlock(var->philosopher_mutex);
		usleep(500);
	}
	return (true);
}
