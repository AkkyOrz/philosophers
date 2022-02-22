#include "helper.h"
#include "philo.h"
#include <pthread.h>

static bool	init_forks(t_args *args, pthread_mutex_t **forks_p)
{
	int	i;
	pthread_mutex_t *forks;

	i = 0;
	forks = (pthread_mutex_t *)ft_calloc(args->number_of_philosophers,
											sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (false);
	while (i < args->number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			return (false);
		}
		i++;
	}
	*forks_p = forks;
	return (true);
}

static void	assign_var_values(t_var *var, t_args *args,
		pthread_mutex_t *forks, t_philosopher *philosopher)
{
	var->args = args;
	var->philosopher = philosopher;
	var->forks = forks;
}

bool	init_var(int argc, char **argv, t_var ***vars_p)
{
	t_args			*args;
	t_philosopher	**philosophers;
	pthread_mutex_t	*forks;
	t_var 			**vars;
	pthread_mutex_t *mutex;
	int i;

	args = NULL;
	philosophers = NULL;
	forks = NULL;
	if (!init_args(argc, argv, &args))
		return (false);
	if (!init_forks(args, &forks))
	{
		free(args);
		return (false);
	}
	if (!init_philosophers(args, &philosophers))
	{
		free(args);
		free(forks);
		return (false);
	}
	vars = ft_calloc(args->number_of_philosophers, sizeof(t_var *));
	if (vars == NULL)
		return (false);
	i = 0;
	while (i < args->number_of_philosophers)
	{
		vars[i] = ft_calloc(1, sizeof(t_var));
		if (vars[i] == NULL)
		{
			free(args);
			free(forks);
			while (i >= 0)
			{
				delete_philosopher(vars[i]->philosopher);
				free(vars[i]);
				i--;
			}
			return (false);
		}
		i++;
	}
	i = 0;
	mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	while (i < args->number_of_philosophers)
	{
		assign_var_values(vars[i], args, forks, philosophers[i]);
		vars[i]->monitor_mutex = mutex;
		i++;
	}

	free(philosophers);
	*vars_p = vars;
	return (true);
}
