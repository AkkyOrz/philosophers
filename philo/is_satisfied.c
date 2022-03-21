/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_satisfied.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:46:42 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 13:46:42 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_is_satisfied(t_is_satisfied *is_satisfied)
{
	bool	is_satisfied_;

	pthread_mutex_lock(&is_satisfied->mutex);
	is_satisfied_ = is_satisfied->is_satisfied;
	pthread_mutex_unlock(&is_satisfied->mutex);
	return (is_satisfied_);
}

void	satisfied(t_is_satisfied *is_satisfied)
{
	pthread_mutex_lock(&is_satisfied->mutex);
	is_satisfied->is_satisfied = true;
	pthread_mutex_unlock(&is_satisfied->mutex);
}
