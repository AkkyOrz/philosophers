#include "philo.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	memset(res, 0, nmemb * size);
	return (res);
}
