#include "helper.h"
#include <unistd.h>

void sleep_in_ms(int wait_ms)
{
	size_t starts_at;
	size_t ends_at;
	size_t sleep_in;
	size_t now;

	starts_at = get_time_ms();
	ends_at = starts_at + wait_ms;
	now = get_time_ms();
	while (now < ends_at)
	{
		sleep_in = (ends_at - now) / 2;
		if (sleep_in > 0)
			usleep(sleep_in * 1000);
		now = get_time_ms();
	}
}
