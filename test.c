#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

void sleep_in_ms(int wait_ms)
{
	size_t starts_at;
	size_t ends_at;
	size_t sleep_in;
	size_t now;

	starts_at = get_time();
	ends_at = starts_at + wait_ms;
	now = get_time();
	while (now < ends_at)
	{
		sleep_in = (ends_at - now) / 2;
		if (sleep_in > 0)
			usleep(sleep_in * 1000);
		now = get_time();
	}
}

int	main(void)
{
	int64_t time, time2;

	while (1)
	{
		time = get_time() + 100;
		sleep_in_ms(100);
		time2 = get_time();
		printf("%lld - %lld = %lld\n", time, time2, time - time2);
	}
}
