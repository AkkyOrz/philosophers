#include "philo.h"

int	get_eaten_count(t_eaten_count *eaten_count)
{
	int	count;

	pthread_mutex_lock(&eaten_count->mutex);
	count = eaten_count->eaten_count;
	pthread_mutex_unlock(&eaten_count->mutex);
	return (count);
}

void	increment_eaten_count(t_eaten_count *eaten_count)
{
	pthread_mutex_lock(&eaten_count->mutex);
	eaten_count->eaten_count++;
	pthread_mutex_unlock(&eaten_count->mutex);
}

bool	is_all_philosopher_satisfied(t_eaten_count *eaten_count, const int num)
{
	int	count;

	count = get_eaten_count(eaten_count);
	if (count == num)
		return (true);
	return (false);
}
