#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>

# define MAX_PHILO 1000

typedef struct s_args
{
	int				number_of_philosophers;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				eat_limit;
	bool			has_limit;
}					t_args;

typedef struct s_philosopher
{
	int				id;
	size_t			last_ate_at;
	int				eat_count;
}					t_philosopher;

typedef struct s_vars
{
	t_args			*args;
	t_philosopher	**philosophers;
}					t_vars;

bool				init_args(int argc, char **argv, t_args **args);
void				delete_args(t_args **args_p);
bool				init_philosophers(t_args *args, t_philosopher ***vars);
bool				init_vars(int argc, char **argv, t_vars **vars);
void delete_vars(t_vars **vars_p);
void delete_philosophers(t_philosopher ***philosophers, int i);
#endif
