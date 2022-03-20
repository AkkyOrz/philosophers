#include "philo.h"
#include <unistd.h>

static bool	is_starved(t_philosopher *philo)
{
	size_t	last_ate_at;
	size_t	die_ms;

	last_ate_at = get_last_ate_at(philo);
	die_ms = philo->args->die_ms;
	if (last_ate_at + die_ms < get_time_ms())
	{
		set_liveness(&philo->vars->liveness, false);
		print_log(philo, STARVING);
		return (true);
	}
	return (false);
}

void	*monitor_philosophers(void *philosophers_ptr)
{
	t_philosopher	**philosophers;
	int				i;
	int				num;

	i = 0;
	philosophers = (t_philosopher **)philosophers_ptr;
	num = philosophers[0]->args->number_of_philosophers;
	while (true)
	{
		i = 0;
		while (i < num)
		{
			if (is_starved(philosophers[i]))
				return (NULL);
			i++;
			usleep(MONITOR_TICK_US);
		}
	}
}
