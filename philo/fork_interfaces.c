#include "philo.h"

bool	get_fork_state(t_fork *fork)
{
	bool	is_taken;

	pthread_mutex_lock(&fork->mutex);
	is_taken = fork->is_taken;
	pthread_mutex_unlock(&fork->mutex);
	return (is_taken);
}

void	set_fork_state(t_fork *fork, bool is_taken)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_taken = is_taken;
	pthread_mutex_unlock(&fork->mutex);
}
