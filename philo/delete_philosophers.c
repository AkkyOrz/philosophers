#include "philo.h"

// don't free args and vars in this function because they are shared
void	delete_philosophers(t_philosopher **philosophers, int num)
{
	num -= 1;
	while (num >= 0)
	{
		free(philosophers[num]);
		num--;
	}
	free(philosophers);
}
