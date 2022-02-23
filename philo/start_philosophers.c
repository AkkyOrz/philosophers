#include "philo.h"
#include <pthread.h>
#include "helper.h"
#include <stdio.h>

void *philosopher(void *var_p)
{
	t_var *var;

	var = *(t_var **)var_p;
	while (true)
	{
		if (!take_forks(var->forks, var->philosopher, var->args->number_of_philosophers))
			break;
		if (!eat(var))
			break;
		if (!put_forks(var->forks, var->philosopher, var->args->number_of_philosophers))
			break;
		if (!go_to_sleep(var))
			break;
		if (!think(var))
			break;
	}
	return (NULL);
}

void *monitor_philosopher(void *var_p)
{
	t_var *var;

	var = *(t_var **)var_p;
	while (true)
	{
		if (!monitor_starving(var))
			break;
	}
	return (NULL);
}

void adjust_time()
{
	size_t current_at = get_time_ms();

	sleep_in_ms(1000 - current_at % 1000);
}

bool start_philosophers(t_var **vars)
{
	int i;
	pthread_t th[MAX_PHILO];
	pthread_t monitor_threads[MAX_PHILO];
	const int n = vars[0]->args->number_of_philosophers;

	adjust_time();
	i = 0;
	while (i < n)
	{
		vars[i]->philosopher->last_ate_at = get_time_ms();
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_create(&th[i], NULL, philosopher, (void *)&vars[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (pthread_create(&monitor_threads[i], NULL, monitor_philosopher,
						(void *)&vars[i]) != 0)
			printf("Error creating monitor thread\n");
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_join(th[i], NULL);
		pthread_join(monitor_threads[i], NULL);
		i++;
	}
	return (true);
}
