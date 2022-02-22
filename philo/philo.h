#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

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

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	TAKING_FORK,
	STARVING
}					t_state;

typedef struct s_philosopher
{
	int				id;
	size_t			last_ate_at;
	int				eat_count;
}					t_philosopher;

// args is read only after init
typedef struct s_vars
{
	t_args			*args;
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t *monitor_mutex;
} t_var;

bool				init_args(int argc, char **argv, t_args **args);
void				delete_args(t_args **args_p);
bool				init_philosophers(t_args *args, t_philosopher ***vars);
bool				init_var(int argc, char **argv, t_var ***vars_p);
void				delete_forks(pthread_mutex_t *forks, int i);
void				delete_philosopher(t_philosopher *philosopher);
void				delete_philosophers(t_philosopher ***philosophers, int i);
bool				start_philosophers(t_var **vars);
void				delete_vars(t_var ***vars);
int get_fork_id(int id, int n);
bool eat(t_var *var);
bool go_to_sleep(t_var *var);
bool think(t_var *var);
bool monitor_starving(t_var *var);
void print_log(const t_philosopher *philosopher, t_state state);

#endif
