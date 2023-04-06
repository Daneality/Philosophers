/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:49:53 by dsas              #+#    #+#             */
/*   Updated: 2023/04/05 20:26:52 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv){
	t_gdata *data;
	t_philo *philos;

	if((argc != 5 && argc!= 6) || !check_input(argv)){
		print_usage();
		exit(0);
	}
	philos = malloc (sizeof(t_philo) * ft_atoi(argv[1]));
	data = parse_data(argc, argc);
	init_philos(philos, data);
	init_threads(philos, data);
	join_threads();
	
}