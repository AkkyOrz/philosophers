#ifndef HELPER_H
# define HELPER_H

# include <stdlib.h>
# include <sys/time.h>

size_t	get_time_ms(void);
int		ft_atoi(char *str);
int		ft_put_error(char *str);
void	*ft_calloc(size_t nmenb, size_t size);
void ft_swap(int *a, int *b);
void sleep_in_ms(int wait_ms);

#endif
