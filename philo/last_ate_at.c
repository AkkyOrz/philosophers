#include "philo.h"

size_t	get_last_ate_at(t_philosopher *philo)
{
	t_last_ate_at	last_ate_at;
	size_t			time_ms;

	last_ate_at = philo->last_ate_at;
	pthread_mutex_lock(&last_ate_at.mutex);
	time_ms = philo->last_ate_at.time_ms;
	pthread_mutex_unlock(&last_ate_at.mutex);
	return (time_ms);
}

void	set_last_ate_at(t_philosopher *philo, size_t time_ms)
{
	t_last_ate_at	last_ate_at;

	last_ate_at = philo->last_ate_at;
	pthread_mutex_lock(&last_ate_at.mutex);
	philo->last_ate_at.time_ms = time_ms;
	pthread_mutex_unlock(&last_ate_at.mutex);
}
