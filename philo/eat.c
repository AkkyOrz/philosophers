#include "philo.h"

bool	eat(t_var *var)
{
	if (is_dead(died))
	{
		put_forks(var->forks, var->philosopher, var->args->number_of_philosophers);
		return (false);
	}
	pthread_mutex_lock(var->philosopher_mutex);
	var->philosopher->last_ate_at = get_time_ms();
	pthread_mutex_unlock(var->philosopher_mutex);
	print_log(var->philosopher, EATING);
	sleep_in_ms(var->args->eat_ms);
	var->philosopher->eat_count++;
	pthread_mutex_lock(var->philosopher_mutex);
	var->philosopher->last_ate_at = get_time_ms();
	pthread_mutex_unlock(var->philosopher_mutex);
	return (true);
}

