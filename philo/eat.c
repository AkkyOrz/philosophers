#include "philo.h"
#include <pthread.h>
#include "helper.h"
#include <stdio.h>
#include <unistd.h>

bool	eat(t_var *var)
{
	const int n = var->args->number_of_philosophers;
	int first;
	int second;

	first = get_fork_id(var->philosopher->id - 1, n);
	second = get_fork_id(var->philosopher->id, n);
	if (first > second)
		ft_swap(&first, &second);
	if (first %2 == 0)
		usleep(500);
	pthread_mutex_lock(&var->forks[first]);
	print_log(var->philosopher, TAKING_FORK);
	pthread_mutex_lock(&var->forks[second]);
	print_log(var->philosopher, TAKING_FORK);
	print_log(var->philosopher, EATING);
	sleep_in_ms(var->args->eat_ms);
	var->philosopher->eat_count++;
	var->philosopher->last_ate_at = get_time_ms();
	pthread_mutex_unlock(&var->forks[second]);
	pthread_mutex_unlock(&var->forks[first]);
	return (true);
}
