/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:26:59 by dsas              #+#    #+#             */
/*   Updated: 2023/04/07 19:30:28 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_philo *p, t_gdata *params)
{
	int			i;
	long int	k;
	pid_t		pid;

	i = -1;
	k = time_now();
	while (++i < p->params->num_p)
	{
		pid = fork();
		if (pid == 0)
		{
			p[i].start = k;
			p[i].meal = k;
			p[i].pid = pid;
			routine(&p[i]);
		}
	}
}


void	init_threads(t_philo *p, t_gdata *params)
{
	int	i;
	int	status;

	//init_mutex(p, params);
		// sem_close(p->params->print);
		// sem_unlink("/output");
		// sem_close(p->params->fork);
		// sem_unlink("/fork");
	i = p->params->num_p;
	while (i > 0)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i++ < p->params->num_p)
				kill(p[i].pid, 9);
			break ;
		}
		i--;
	}
}
