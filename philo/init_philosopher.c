#include "helper.h"
#include "philo.h"
#include <stdio.h>
#include <string.h>



static void	init_single_philosopher(t_philosopher *philo, int i)
{
	philo->id = i + 1;
	philo->last_ate_at = get_time_ms();
	philo->eat_count = 0;
}

static t_philosopher	**init_philosophers_helper(t_args *args)
{
	t_philosopher	**philosophers;
	const int number_of_philosophers = args->number_of_philosophers;
	int		i;

	philosophers = ft_calloc(args->number_of_philosophers, sizeof(t_philosopher *));
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		philosophers[i] = ft_calloc(1, sizeof(t_philosopher));
		if (philosophers[i] == NULL)
		{
			delete_philosophers(&philosophers, i - 1);
			return (NULL);
		}
		init_single_philosopher(philosophers[i], i);
		i++;
	}
	return (philosophers);
}

bool				init_philosophers(t_args *args, t_philosopher ***philosophers)
{
	t_philosopher	**philosophers_p;

	philosophers_p = init_philosophers_helper(args);
	if (philosophers_p == NULL)
	{
		printf("Error: could not allocate memory for philosophers\n");
		return (false);
	}
	*philosophers = philosophers_p;
	return (true);
}
