#include "helper.h"
#include "philo.h"
#include <stdio.h>

bool	monitor_starving(t_var *var)
{
	const t_args		*args;

	args = var->args;
	while (true)
	{
		if (var->philosopher->last_ate_at + (size_t)args->die_ms < get_time_ms())
		{
			print_log(var->philosopher, STARVING);
			return (false);
		}
	}
	return (true);
}