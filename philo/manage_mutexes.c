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
		i++;
	}
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&philosophers[i]->last_ate_at.mutex, NULL) != 0)
			return (false);
		i++;
	}
	if (pthread_mutex_init(&vars->liveness.mutex, NULL) != 0)
		return (false);
	return (true);
}

bool destroy_mutexes(t_philosopher **philosophers)
{
	t_vars		*vars;
	const int	num = philosophers[0]->args->number_of_philosophers;
	int			i;

	vars = philosophers[0]->vars;
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&vars->forks[i].mutex) != 0)
			return (false);
		i++;
	}
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&philosophers[i]->last_ate_at.mutex) != 0)
			return (false);
		i++;
	}
	if (pthread_mutex_destroy(&vars->liveness.mutex) != 0)
		return (false);
	return (true);
}
