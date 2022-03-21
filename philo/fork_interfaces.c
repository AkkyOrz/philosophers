/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_interfaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:49:42 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 00:49:42 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_fork_state(t_fork *fork)
{
	bool	is_taken;

	pthread_mutex_lock(&fork->mutex);
	is_taken = fork->is_taken;
	pthread_mutex_unlock(&fork->mutex);
	return (is_taken);
}

void	set_fork_state(t_fork *fork, bool is_taken)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_taken = is_taken;
	pthread_mutex_unlock(&fork->mutex);
}
