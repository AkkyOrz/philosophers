#include "philo.h"

void *simulate_single_philosopher(void *philosopher_ptr)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philosopher_ptr;
	while (true)
	{
		if (!take_forks(philosopher, philosopher->vars->forks, philosopher->args->number_of_philosophers))
			return (NULL);
	}
	return (NULL);
}
