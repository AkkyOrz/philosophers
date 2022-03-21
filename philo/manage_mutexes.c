#include "philo.h"

bool	init_mutexes_for_philosopher(t_philosopher **philosophers)
{
	int	i;
	const int	num = philosophers[0]->args->number_of_philosophers;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&philosophers[i]->last_ate_at.mutex, NULL) != 0)
			return (false);
		if (pthread_mutex_init(&philosophers[i]->is_satisfied.mutex, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

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
	if (!init_mutexes_for_philosopher(philosophers))
		return (false);
	if (pthread_mutex_init(&vars->liveness.mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&vars->eaten_count.mutex, NULL) != 0)
		return (false);
	return (true);
}

bool	destroy_mutexes_for_philosopher(t_philosopher **philosophers)
{
	int	i;
	const int	num = philosophers[0]->args->number_of_philosophers;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&philosophers[i]->last_ate_at.mutex) != 0)
			return (false);
		if (pthread_mutex_destroy(&philosophers[i]->is_satisfied.mutex) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	destroy_mutexes(t_philosopher **philosophers)
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
	if (pthread_mutex_destroy(&vars->liveness.mutex) != 0)
		return (false);
	if (pthread_mutex_destroy(&vars->eaten_count.mutex) != 0)
		return (false);
	return (true);
}
