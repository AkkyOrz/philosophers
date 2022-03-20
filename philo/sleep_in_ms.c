#include "philo.h"
#include <unistd.h>

void sleep_in_ms(size_t ms)
{
	size_t	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < ms)
		usleep(TICK_US);
	return ;
}
