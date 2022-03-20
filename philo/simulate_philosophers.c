#include "philo.h"

bool	simulate_philosophers(t_philosopher **philosophers)
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
