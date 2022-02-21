#include "philo.h"

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
