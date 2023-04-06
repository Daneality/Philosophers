/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:25:28 by dsas              #+#    #+#             */
/*   Updated: 2023/04/06 14:48:22 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_gdata
{
	int				ready;
	int				tte;
	int				ttd;
	int				tts;
	int				tme;
	int				over;
	int				num_p;
	int				check_tme;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
} t_gdata;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		thread;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_gdata			*params;
} t_philo;

uint64_t	ft_get_time(void);
void		ft_usleep(uint64_t wait_time);
int			ft_atoi(const char *nptr);
int			check_input(char **av);
void		init_philos(t_philo *p, t_gdata *params);
void		init_threads(t_philo *p, t_gdata *params);

#endif
