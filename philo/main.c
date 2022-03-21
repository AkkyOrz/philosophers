/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:03 by akito             #+#    #+#             */
/*   Updated: 2022/03/21 12:28:03 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philosopher	**philosophers;

	philosophers = init_philosophers(argc, argv);
	if (philosophers == NULL)
		return (EXIT_FAILURE);
	if (!init_mutexes(philosophers))
		return (EXIT_FAILURE);
	if (!simulate_philosophers(philosophers))
		return (EXIT_FAILURE);
	destroy_mutexes(philosophers);
	delete_all(philosophers, philosophers[0]->args->number_of_philosophers);
	return (0);
}
