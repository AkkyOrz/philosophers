#include "philo.h"

void delete_vars(t_vars **vars)
{
	if ((*vars)->philosophers != NULL)
	{
		delete_philosophers(&(*vars)->philosophers, (*vars)->args->number_of_philosophers - 1);
	}
	delete_args(&(*vars)->args);
	free(*vars);
	*vars = NULL;
}
