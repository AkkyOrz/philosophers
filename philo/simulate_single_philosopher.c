#include "philo.h"
#include <unistd.h>
#include <stdio.h>

bool	eat(t_philosopher *philosopher)
{
	if (!print_log(philosopher, EATING))
	{
		put_forks(philosopher, philosopher->vars->forks);
		return (false);
	}
	set_last_ate_at(philosopher, get_time_ms());
	sleep_in_ms(philosopher->args->eat_ms);
	philosopher->eat_count++;
	return (put_forks(philosopher, philosopher->vars->forks));
}

bool go_to_sleep(t_philosopher *philosopher)
{
	if (!print_log(philosopher, SLEEPING))
		return (false);
	sleep_in_ms(philosopher->args->sleep_ms);
	return (true);
}

bool think(t_philosopher *philosopher)
{
	if (!print_log(philosopher, THINKING))
		return (false);
	// usleep(500);
	return (true);
}


void *simulate_single_philosopher(void *philosopher_ptr)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philosopher_ptr;
	if (philosopher->id % 2 == 0)
		usleep(1500);
	while (true)
	{
		if (!take_forks(philosopher, philosopher->vars->forks))
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
