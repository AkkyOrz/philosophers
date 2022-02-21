#include "philo.h"

void	delete_args(t_args **args_p)
{
	free(*args_p);
	*args_p = NULL;
}
