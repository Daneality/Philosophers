/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:25:28 by dsas              #+#    #+#             */
/*   Updated: 2023/03/20 11:55:01 by dsas             ###   ########.fr       */
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

uint64_t	ft_get_time(void);
void		ft_usleep(uint64_t wait_time);
int			ft_atoi(const char *nptr);

typedef struct s_gdata
{
	int				ready;
	int				tte;
	int				ttd;
	int				tts;
	int				tme;
	int				over;
	int				nop;
	int				check_tme;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
} t_gdata;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		phils;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_gdata			*data;
} t_philo;

#endif
