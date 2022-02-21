#include "philo.h"
#include <pthread.h>


void *philosopher(void *var_p)
{
	(void)var_p;
	return (NULL);
}

bool start_philosophers(t_var *vars)
{
	int i;
	pthread_t th[MAX_PHILO];
	const int n = vars->args->number_of_philosophers;

	i = 0;
	while (i < n)
	{
		pthread_create(&th[i], NULL, philosopher, (void *)&vars[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	return (true);
}
