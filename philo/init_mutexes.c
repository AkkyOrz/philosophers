#include "philo.h"

bool	init_mutexes(t_philosopher **philosophers)
{
	t_vars		*vars;
	const int	num = philosophers[0]->args->number_of_philosophers;
	int			i;

	vars = philosophers[0]->vars;
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&vars->forks[i].mutex, NULL) != 0)
			return (false);
	}
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&philosophers[i]->last_ate_at.mutex, NULL) != 0)
			return (false);
	}
	if (pthread_mutex_init(&vars->liveness.mutex, NULL) != 0)
		return (false);
	return (true);
}
