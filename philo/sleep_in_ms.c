#include "helper.h"
#include <unistd.h>

void sleep_in_ms(int wait_ms)
{
	size_t starts_at;
	size_t sleep_in;

	starts_at = get_time_ms();
	while (get_time_ms() - starts_at < (size_t )wait_ms)
	{
		sleep_in = ((size_t )wait_ms - (get_time_ms() - starts_at)) / 2;
		if (sleep_in < 100)
			sleep_in = 100;
		usleep(sleep_in);
	}
}
