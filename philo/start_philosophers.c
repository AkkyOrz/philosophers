#include "philo.h"

bool start_philosophers(t_philo **philosophers)
{
	int i;
	pthread_t th[MAX_PHILO];

	i = 0;
	while (i < )
	{
		pthread_create(&philosophers[i]->thread, NULL, &philo_thread, philosophers[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(philosophers[i]->thread, NULL);
		i++;
	}
	return (true);
}
