#include "philo.h"

void	delete_vars(t_var ***vars)
{
	const int size = (*vars)[0]->args->number_of_philosophers;
	int	i;

	i = 0;
	delete_args(&(*vars)[0]->args);
	delete_forks((*vars)[0]->forks, size);
	while (i < size)
	{
		delete_philosopher((*vars)[i]->philosopher);
		free((*vars)[i]);
		i++;
	}
	free(*vars);
	*vars = NULL;
}
