#include "philo.h"
#include <stdio.h>

t_pair	select_forks(const t_philosopher *philosopher)
{
	t_pair	pair_elm;
	t_pair	*pair;

	pair = &pair_elm;
	pair->first = philosopher->left_fork_id;
	pair->second = philosopher->right_fork_id;
	if (philosopher->id % 2 == 0)
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

bool	take_fork(t_philosopher *philosopher, t_fork *fork)
{
	bool	is_taken;

	pthread_mutex_lock(&fork->mutex);
	is_taken = fork->is_taken;
	if (!is_taken)
		fork->is_taken = true;
	return (print_log(philosopher, TAKING_FORK));
}

bool	take_forks(t_philosopher *philosopher, t_fork *forks)
{
	t_pair	pair;

	pair = select_forks(philosopher);
	if (!take_fork(philosopher, &forks[pair.first]))
		return (false);
	if (!take_fork(philosopher, &forks[pair.second]))
		return (false);
	return (true);
}

bool put_forks(t_philosopher *philosopher, t_fork *forks)
{
	t_pair	pair;

	pair = select_forks(philosopher);
	forks[pair.second].is_taken = false;
	pthread_mutex_unlock(&forks[pair.second].mutex);
	forks[pair.first].is_taken = false;
	pthread_mutex_unlock(&forks[pair.first].mutex);
	return (true);
}
