#include "philo.h"
#include "helper.h"

bool	init_vars(int argc, char **argv, t_vars **vars)
{
	*vars = ft_calloc(1, sizeof(t_vars));
	if (*vars == NULL)
		return (false);
	if (!init_args(argc, argv, &(*vars)->args))
		return (false);
	if (!init_philosophers((*vars)->args, &(*vars)->philosophers))
		return (false);
	return (true);
}
