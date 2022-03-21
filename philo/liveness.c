/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liveness.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:21:05 by akito             #+#    #+#             */
/*   Updated: 2022/03/20 21:21:05 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_liveness(t_liveness *liveness)
{
	bool	is_alive;

	pthread_mutex_lock(&liveness->mutex);
	is_alive = liveness->is_alive;
	pthread_mutex_unlock(&liveness->mutex);
	return (is_alive);
}

void	set_liveness(t_liveness *liveness, bool is_alive)
{
	pthread_mutex_lock(&liveness->mutex);
	liveness->is_alive = is_alive;
	pthread_mutex_unlock(&liveness->mutex);
}
