/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:49:53 by dsas              #+#    #+#             */
/*   Updated: 2023/04/10 17:39:21 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->params->num_p)
		pthread_join(p[i].thread, (void *)&p[i]);
}

int	main(int argc, char **argv)
{
	t_gdata	*data;
	t_philo	*philos;

	if ((argc != 5 && argc != 6) || !check_input(argv))
	{
		ft_error_input();
		exit(0);
	}
	philos = malloc (sizeof(t_philo) * ft_atoi(argv[1]));
	data = parse_data(argv);
	init_philos(philos, data);
	init_threads(philos, data);
	join_threads(philos);
	free_all(philos);
}
