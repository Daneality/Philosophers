/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:09:15 by dsas              #+#    #+#             */
/*   Updated: 2023/04/07 19:26:15 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *p)
{
	t_gdata	*par;

	par = p->params;
	sem_wait(par->fork);
	ft_print(p, 4);
	sem_wait(par->fork);
	ft_print(p, 4);
	p->meal = time_now();
	ft_print(p, 1);
	ft_usleep(par->tte);
	p->iter++;
	sem_post(par->fork);
	sem_post(par->fork);
}

void	routine(t_philo *p)
{
	t_gdata	*par;

	par = p->params;
	while (!par->dead)
	{
		if (par->num_p == 1)
		{
			ft_usleep(par->ttd);
			printf("%ld %d %s\n", p->meal - p->start \
			+ p->params->ttd, p->id, "died\n");
			exit (1);
		}
		ft_eat(p);
		if (p->iter == par->tme)
			exit (0);
		ft_print(p, 2);
		ft_usleep(par->tts);
		ft_print(p, 3);
	}
	exit (0);
}


