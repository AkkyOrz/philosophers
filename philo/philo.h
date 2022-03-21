#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>

# define MAX_PHILO 1000
# define MONITOR_TICK_US 900
# define TICK_US 100

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	TAKING_FORK,
	STARVING
}					t_state;

typedef struct s_args
{
	int				number_of_philosophers;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				eat_limit;
	bool			has_limit;
}					t_args;

typedef struct s_fork
{
	bool			is_taken;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_liveness
{
	bool			is_alive;
	pthread_mutex_t	mutex;
}					t_liveness;

typedef struct s_eaten_count
{
	int				eaten_count;
	pthread_mutex_t	mutex;
}					t_eaten_count;

typedef struct s_last_ate_at
{
	size_t			time_ms;
	pthread_mutex_t	mutex;
}					t_last_ate_at;

typedef struct s_is_satisfied
{
	bool			is_satisfied;
	pthread_mutex_t	mutex;
}					t_is_satisfied;

// args is read only after init
typedef struct s_vars
{
	t_fork			*forks;
	t_liveness		liveness;
	t_eaten_count	eaten_count;
}					t_vars;

typedef struct s_philosopher
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	t_last_ate_at	last_ate_at;
	int				eat_count;
	t_is_satisfied	is_satisfied;
	t_args			*args;
	t_vars			*vars;
}					t_philosopher;

typedef struct s_pair
{
	int				first;
	int				second;
}					t_pair;

t_philosopher		**init_philosophers(int argc, char **argv);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *nptr);
bool				ft_isdigit(int c);
void				ft_swap(int *a, int *b);
void				delete_philosophers(t_philosopher **philosophers, int num);
size_t				get_time_ms(void);
bool				init_mutexes(t_philosopher **philosophers);
bool				simulate_philosophers(t_philosopher **philosophers);
void				*simulate_single_philosopher(void *philosopher_ptr);
void				*simulate_alone_philosopher(void *philosopher_ptr);
size_t				get_last_ate_at(t_philosopher *philo);
void				set_last_ate_at(t_philosopher *philo, size_t time_ms);
void				set_liveness(t_liveness *liveness, bool is_alive);
size_t				get_liveness(t_liveness *liveness);
void				*monitor_philosophers(void *philosophers_ptr);
bool				print_log(const t_philosopher *philosopher, t_state state);
bool				get_fork_state(t_fork *fork);
void				set_fork_state(t_fork *fork, bool is_taken);
int					get_fork_id(int id, int n);
bool				take_forks(t_philosopher *philosopher);
bool				put_forks(t_philosopher *philosopher);
void				sleep_in_ms(size_t ms);
bool				destroy_mutexes(t_philosopher **philosophers);
void				delete_all(t_philosopher **philosophers, int num);
int					get_eaten_count(t_eaten_count *eaten_count);
void				increment_eaten_count(t_eaten_count *eaten_count);
bool				is_all_philosopher_satisfied(t_eaten_count *eaten_count,
					const int num);
bool				get_is_satisfied(t_is_satisfied *is_satisfied);
void				satisfied(t_is_satisfied *is_satisfied);

#endif
