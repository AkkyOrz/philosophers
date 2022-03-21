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

void	delete_all(t_philosopher **philosophers, int num)
{
	t_args *args;
	t_vars *vars;

	args = philosophers[0]->args;
	vars = philosophers[0]->vars;
	delete_philosophers(philosophers, num);
	free(args);
	free(vars->forks);
	free(vars);
}
