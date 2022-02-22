#include "philo.h"
#include "helper.h"

bool go_to_sleep(t_var *var)
{
	const int sleep_ms = var->args->sleep_ms;

	print_log(var->philosopher, SLEEPING);
	sleep_in_ms(sleep_ms);
	return (true);
}
