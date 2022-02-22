#include "philo.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_var	**vars;

	if (!init_var(argc, argv, &vars))
	{
		delete_vars(&vars);
		return (EXIT_FAILURE);
	}
	if (!start_philosophers(vars))
		return (EXIT_FAILURE);
	delete_vars(&vars);
}
