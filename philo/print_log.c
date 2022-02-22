#include "helper.h"
#include "philo.h"
#include <stdio.h>

void	print_log(const t_philosopher *philosopher, t_state state)
{
	const char	*state_str;
	const int	id = philosopher->id;

	if (state == EATING)
		state_str = "is \033[32meating\033[0m";
	else if (state == TAKING_FORK)
		state_str = "has \033[33mtaken a fork\033[0m";
	else if (state == THINKING)
		state_str = "is \033[34mthinking\033[0m";
	else if (state == SLEEPING)
		state_str = "is \033[35msleeping\033[0m";
	else if (state == STARVING)
		state_str = "is \033[31mdied\033[0m";
	printf("%lu %d %s\n", get_time_ms(), id, state_str);
}
