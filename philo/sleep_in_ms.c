#include "helper.h"
#include <unistd.h>

void sleep_in_ms(int wait_ms)
{
	size_t starts_at;

	starts_at = get_time_ms();
	while (get_time_ms() - starts_at < (size_t )wait_ms)
	{
		usleep(1000);
	}
}
