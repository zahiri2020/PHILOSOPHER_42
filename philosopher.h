/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:03:23 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/18 15:28:29 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>

typedef struct s_data
{
	int				n__philo;
	long			t_eat;
	long			t_dead;
	long			t_sleep;
	long			n_mails;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
}				t_data;

#endif