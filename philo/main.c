#include "philo.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_args	*args;
	t_philo	**philosophers;

	if (!Init_args(argc, argv, &args))
		return (EXIT_FAILURE);
	if (!Init_philosophers(args, &philosophers))
		return (EXIT_FAILURE);
}
