#include "philo.h"
#include "helper.h"
#include <unistd.h>

void select_forks(const int philo_id, const int n, t_pair *pair)
{
	pair->first = get_fork_id(philo_id, n);
	pair->second = get_fork_id(philo_id + 1, n);
	if (philo_id % 2 != 0)
		ft_swap(&pair->first, &pair->second);
}

bool take_forks(pthread_mutex_t *forks, t_philosopher *philosopher, const int n)
{
	t_pair pair;

	if (philosopher->id % 2 == 1)
		usleep(200);
	select_forks(philosopher->id, n, &pair);
	pthread_mutex_lock(&forks[pair.first]);
	print_log(philosopher, TAKING_FORK);
	pthread_mutex_lock(&forks[pair.second]);
	print_log(philosopher, TAKING_FORK);
	return (true);
}

bool put_forks(pthread_mutex_t *forks, t_philosopher *philosopher, const int n)
{
	t_pair pair;

	select_forks(philosopher->id, n, &pair);
	pthread_mutex_unlock(&forks[pair.second]);
	pthread_mutex_unlock(&forks[pair.first]);
	return (true);
}
