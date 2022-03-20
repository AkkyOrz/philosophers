#include "philo.h"

t_vars	*init_vars(int num)
{
	t_vars	*vars;
	t_fork	*forks;
	int		i;

	vars = (t_vars *)ft_calloc(sizeof(t_vars), 1);
	forks = (t_fork *)ft_calloc(sizeof(t_fork), num);
	if (forks == NULL || vars == NULL)
	{
		free(forks);
		free(vars);
		return (NULL);
	}
	i = -1;
	while (++i < num)
		forks[i].is_taken = false;
	vars->forks = forks;
	vars->liveness.is_alive = true;
	return (vars);
}

t_args	*init_args(int argc, char **argv)
{
	t_args	*args;

	if (!(5 <= argc && argc <= 6))
		return (NULL);
	args = (t_args *)ft_calloc(sizeof(t_args), 1);
	if (args == NULL)
		return (NULL);
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->die_ms = ft_atoi(argv[2]);
	args->eat_ms = ft_atoi(argv[3]);
	args->sleep_ms = ft_atoi(argv[4]);
	if (argc == 6)
		args->eat_limit = ft_atoi(argv[5]);
	args->has_limit = (argc == 6);
	if (args->number_of_philosophers <= 0 || args->die_ms <= 0
		|| args->eat_ms <= 0 || args->sleep_ms <= 0
		|| (args->has_limit && args->eat_limit <= 0))
	{
		free(args);
		return (NULL);
	}
	return (args);
}

t_philosopher	*new_philosopher(t_args *args, t_vars *vars, int index)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)ft_calloc(sizeof(t_philosopher), 1);
	if (philosopher == NULL)
		return (NULL);
	philosopher->id = index + 1;
	philosopher->left_fork_id = get_fork_id(index, args->number_of_philosophers);
	philosopher->right_fork_id = get_fork_id(index + 1, args->number_of_philosophers);
	philosopher->last_ate_at.time_ms = get_time_ms();
	philosopher->eat_count = 0;
	philosopher->args = args;
	philosopher->vars = vars;
	return (philosopher);
}

t_philosopher	**create_philosophers(t_args *args, t_vars *vars)
{
	t_philosopher	**philosophers;
	int				i;

	philosophers = (t_philosopher **)ft_calloc(sizeof(t_philosopher *),
			args->number_of_philosophers);
	if (philosophers == NULL)
	{
		free(args);
		free(vars);
		return (NULL);
	}
	i = -1;
	while (++i < args->number_of_philosophers)
	{
		philosophers[i] = new_philosopher(args, vars, i);
		if (philosophers[i] == NULL)
		{
			free(args);
			free(vars);
			delete_philosophers(philosophers, i);
			return (NULL);
		}
	}
	return (philosophers);
}

t_philosopher	**init_philosophers(int argc, char **argv)
{
	t_args	*args;
	t_vars	*vars;

	args = init_args(argc, argv);
	if (args == NULL)
		return (false);
	vars = init_vars(args->number_of_philosophers);
	if (vars == NULL)
	{
		free(args);
		return (false);
	}
	return (create_philosophers(args, vars));
}
