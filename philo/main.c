#include "philo.h"

int	main(int argc, char **argv)
{
	t_philosopher	**philosophers;

	philosophers = init_philosophers(argc, argv);
	if (philosophers == NULL)
		return (EXIT_FAILURE);
	if (!init_mutexes(philosophers))
		return (EXIT_FAILURE);
	if (!simulate_philosophers(philosophers))
		return (EXIT_FAILURE);
	return (0);
}
