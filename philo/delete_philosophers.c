/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:03 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 14:08:12 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// don't free args and vars in this function because they are shared
void	delete_philosophers(t_philosopher **philosophers, int num)
{
	num -= 1;
	while (num >= 0)
	{
		free(philosophers[num]);
		num--;
	}
	free(philosophers);
}

void	delete_all(t_philosopher **philosophers, int num)
{
	t_args	*args;
	t_vars	*vars;

	args = philosophers[0]->args;
	vars = philosophers[0]->vars;
	delete_philosophers(philosophers, num);
	free(args);
	free(vars->forks);
	free(vars);
}
