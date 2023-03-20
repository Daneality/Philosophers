/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:49:53 by dsas              #+#    #+#             */
/*   Updated: 2023/03/20 10:51:59 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv){
	t_gdata * data;

	if(argc != 5 && argc!= 6){
		print_usage();
		exit(0);
	}
	data = parse_data(argc, argc);
	
}