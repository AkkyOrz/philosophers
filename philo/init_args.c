#include "helper.h"
#include "philo.h"
#include <stdio.h>
#include <string.h>
static bool		check_args(t_args *args);
static t_args	*init_args_helper(int argc, char **argv);

static t_args	*init_args_helper(int argc, char **argv)
{
	t_args	*args;

	args = ft_calloc(1, sizeof(t_args));
	if (args == NULL)
		return (NULL);
	args->number_of_philosophers = atoi(argv[1]);
	args->die_ms = atoi(argv[2]);
	args->eat_ms = atoi(argv[3]);
	args->sleep_ms = atoi(argv[4]);
	if (argc == 6)
	{
		args->eat_limit = atoi(argv[5]);
		args->has_limit = true;
	}
	return (args);
}

static bool	check_args(t_args *args)
{
	if (args->number_of_philosophers < 1 || args->number_of_philosophers > 1000)
	{
		printf("Number of philosophers must be between 1 and 1000\n");
		return (false);
	}
	return (true);
}

bool	init_args(int argc, char **argv, t_args **args)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo <num> <die> <eat> <sleep>\n");
		return (false);
	}
	*args = init_args_helper(argc, argv);
	if (*args == NULL)
		return (false);
	if (check_args(*args) == false)
	{
		delete_args(args);
		return (false);
	}
	return (true);
}
