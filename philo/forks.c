#include "philo.h"
#include <stdio.h>

t_pair	select_forks(const t_philosopher *philosopher)
{
	t_pair	pair_elm;
	t_pair	*pair;

	pair = &pair_elm;
	pair->first = philosopher->left_fork_id;
	pair->second = philosopher->right_fork_id;
	if (pair->first > pair->second)
		ft_swap(&pair->first, &pair->second);
	return (pair_elm);
}

bool	take_a_fork(t_philosopher *philosopher, t_pair fork_ids, bool is_first)
{
	int fork_id;

	if (is_first)
		fork_id = fork_ids.first;
	else
		fork_id = fork_ids.second;
	pthread_mutex_lock(&philosopher->vars->forks[fork_id].mutex);
	if (!print_log(philosopher, TAKING_FORK))
	{
		pthread_mutex_unlock(&philosopher->vars->forks[fork_id].mutex);
		if (!is_first)
			pthread_mutex_unlock(&philosopher->vars->forks[fork_ids.first].mutex);
		return (false);
	}
	if (!philosopher->vars->forks[fork_id].is_taken)
		philosopher->vars->forks[fork_id].is_taken = true;
	return (true);
}

bool	take_forks(t_philosopher *philosopher)
{
	t_pair	pair;

	pair = select_forks(philosopher);
	if (!take_a_fork(philosopher, pair, true))
		return (false);
	if (!take_a_fork(philosopher, pair, false))
		return (false);
	return (true);
}

bool put_forks(t_philosopher *philosopher)
{
	t_pair	pair;

	pair = select_forks(philosopher);
	philosopher->vars->forks[pair.second].is_taken = false;
	pthread_mutex_unlock(&philosopher->vars->forks[pair.second].mutex);
	philosopher->vars->forks[pair.first].is_taken = false;
	pthread_mutex_unlock(&philosopher->vars->forks[pair.first].mutex);
	return (true);
}
