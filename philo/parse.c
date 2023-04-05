/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:03:32 by dsas              #+#    #+#             */
/*   Updated: 2023/04/05 16:23:43 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		i++;
	}
	if (ft_atoi(av[0]) <= 0 || ft_atoi(av[1]) <= 0 || \
	ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0)
		return (0);
	return (1);
}


t_gdata *parse_data(int argc, char **argv)
{
	char	*checked;
	char 	*marked;
}

