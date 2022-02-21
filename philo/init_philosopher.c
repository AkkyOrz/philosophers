#include "helper.h"
#include "philo.h"
#include <string.h>

static void	clear_philosophers(t_philo **philosophers, int i)
{
	while (i >= 0)
	{
		free(philosophers[i]);
		i--;
	}
	free(philosophers);
}

static void	init_single_philosopher(t_philo *philo, t_args *args, int i)
{
	philo->id = i;
	philo->arg = args;
	philo->last_ate_at = get_time_ms();
	philo->eat_count = 0;
	philo->arg = args;
}

static t_philo	**init_philosophers(t_args *args)
{
	t_philo	**philosophers;
	int		i;

	philosophers = ft_calloc(args->number_of_philosophers, sizeof(t_philo *));
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < args->number_of_philosophers)
	{
		philosophers[i] = ft_calloc(1, sizeof(t_philo));
		if (philosophers[i] == NULL)
		{
			clear_philosophers(philosophers, i - 1);
			return (NULL);
		}
		init_single_philosopher(philosophers[i], args, i);
		i++;
	}
	return (philosophers);
}

bool	Init_philosophers(t_args *args, t_philo ***philosophers)
{
	t_philo	**philosophers_p;

	philosophers_p = init_philosophers(args);
	if (philosophers_p == NULL)
		return (false);
	*philosophers = philosophers_p;
	return (true);
}
