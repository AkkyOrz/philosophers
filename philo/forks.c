#include "philo.h"
#include <stdio.h>

t_pair	select_forks(const int philo_id, const int n)
{
	t_pair	pair_elm;
	t_pair	*pair;

	pair = &pair_elm;
	pair->first = get_fork_id(philo_id, n);
	pair->second = get_fork_id(philo_id + 1, n);
	if (philo_id % 2 == 0)
	{
		if (pair->first > pair->second)
			ft_swap(&pair->first, &pair->second);
	}
	else
	{
		ft_swap(&pair->first, &pair->second);
	}
	return (pair_elm);
}

bool	take_fork(t_philosopher *philosopher, t_fork *fork, int i)
{
	bool	is_taken;

	pthread_mutex_lock(&fork->mutex);
	is_taken = fork->is_taken;
	if (!is_taken)
		fork->is_taken = true;
	else
		printf("Error: fork %d is already taken\n", i);
	return (print_log(philosopher, TAKING_FORK));
}

bool	take_forks(t_philosopher *philosopher, t_fork *forks, const size_t n)
{
	t_pair	pair;

	pair = select_forks(philosopher->id, n);
	if (!take_fork(philosopher, &forks[pair.first], pair.first))
		return (false);
	if (!take_fork(philosopher, &forks[pair.second], pair.second))
		return (false);
	return (true);
}
