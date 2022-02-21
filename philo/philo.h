#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int		number_of_philosophers;
	int		die_ms;
	int		eat_ms;
	int		sleep_ms;
	int		eat_limit;
	bool	has_limit;
}			t_args;

typedef struct s_philo
{
	int		id;
	size_t	last_ate_at;
	int		eat_count;
	t_args	*arg;
}			t_philo;

bool		Init_args(int argc, char **argv, t_args **args);
void		delete_args(t_args **args_p);
bool		Init_philosophers(t_args *args, t_philo ***philosophers);
#endif
