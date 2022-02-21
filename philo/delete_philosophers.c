#include "philo.h"

void	delete_philosopher(t_philosopher *philosopher)
{
	free(philosopher);
}

void	delete_philosophers(t_philosopher ***philosophers, int i)
{
	while (i >= 0)
	{
		free((*philosophers)[i]);
		i--;
	}
	free(*philosophers);
	philosophers = NULL;
}
