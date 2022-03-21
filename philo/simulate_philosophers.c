#include "philo.h"
#include <stdio.h>

bool thread_multiple_philosophers(t_philosopher **philosophers)
{
	pthread_t	th[MAX_PHILO];
	pthread_t	mon;
	const int	num = philosophers[0]->args->number_of_philosophers;
	int			i;

	i = 0;
	while (i < num)
	{
		if (pthread_create(&th[i], NULL, &simulate_single_philosopher,
				philosophers[i]))
			return (false);
		i++;
	}
	if (pthread_create(&mon, NULL, &monitor_philosophers, philosophers) != 0)
		return (false);
	i = 0;
	while (i < num)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (false);
		i++;
	}
	if (pthread_join(mon, NULL) != 0)
		return (false);
	return (true);
}

bool thread_single_philosopher(t_philosopher **philosophers)
{
	pthread_t	th;
	pthread_t	mon;

	if (pthread_create(&th, NULL, &simulate_alone_philosopher, philosophers))
		return (false);
	if (pthread_create(&mon, NULL, &monitor_philosophers, philosophers))
		return (false);
	if (pthread_join(th, NULL) != 0)
		return (false);
	if (pthread_join(mon, NULL) != 0)
		return (false);
	return (true);
}

bool	simulate_philosophers(t_philosopher **philosophers)
{
	const int	num = philosophers[0]->args->number_of_philosophers;
	if (num == 1)
		return (thread_single_philosopher(philosophers));
	else
		return (thread_multiple_philosophers(philosophers));
}
