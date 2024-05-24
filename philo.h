/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:03:23 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/24 22:43:15 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	int				n_philo;
	long			t_eat;
	long			t_dead;
	long			t_sleep;
	long			n_mails;
	int				*flag;
	long			t_start;
	pthread_mutex_t	*forks;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				flag;
	t_data			*info;
	long long 		last_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		philo;
}				t_philo;

int			init_philo(t_philo *p, char **av);
long long	get_time(void);
void		ft_sleep(int t);
int			create_philo(t_philo *p);
void		eating(t_philo *p);
void		sleeping(t_philo *p);
void		thinking(t_philo *p);

#endif