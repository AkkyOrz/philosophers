#include "philo.h"

bool think(t_var *var)
{
	print_log(var->philosopher, THINKING);
	return (true);
}
