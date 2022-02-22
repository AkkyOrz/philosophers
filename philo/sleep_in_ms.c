#include "helper.h"
#include <unistd.h>

void sleep_in_ms(int wait_ms)
{
	size_t starts_at;
	size_t ends_at;
	size_t sleep_in;

	starts_at = get_time_ms();
	ends_at = starts_at + wait_ms;
	while (get_time_ms() < ends_at)
	{
		sleep_in = (ends_at - get_time_ms()) / 2;
		usleep(sleep_in * 1000);
	}
}
