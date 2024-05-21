/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:03:23 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/21 20:54:24 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data
{
	int				n_philo;
	long			t_eat;
	long			t_dead;
	long			t_sleep;
	long			n_mails;
	long			time;
	pthread_mutex_t	*fork;
}				t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	philo;
	t_data		*info;
}				t_philo;

int	init_data(t_philo *p, char **av);

#endif