#include "philo.h"
#include <pthread.h>
#include "helper.h"
#include <stdio.h>
#include <unistd.h>

bool	eat(t_var *var)
{
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
