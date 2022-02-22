#include "philo.h"

int get_fork_id(int id, int n)
{

	if (0 <= id && id < n)
		return (id);
	else if (id <= 0)
		return (n - 1);
	else
		return (0);
}
