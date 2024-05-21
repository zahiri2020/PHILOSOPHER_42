/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:03:23 by ezahiri           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/21 20:54:24 by ezahiri          ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2024/05/18 15:28:29 by ezahiri          ###   ########.fr       */
=======
/*   Updated: 2024/05/17 21:34:51 by ezahiri          ###   ########.fr       */
>>>>>>> 47bc9a18e591aa944e49062ae9faa0f93227deac
>>>>>>> 84b520632d6e493ea0ed56d98c70a623d7109ca1
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
<<<<<<< HEAD
# include <string.h>
=======
# include <sys/time.h>
>>>>>>> 84b520632d6e493ea0ed56d98c70a623d7109ca1

<<<<<<< HEAD
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

<<<<<<< HEAD
typedef struct s_philo
{
	int			id;
	pthread_t	philo;
	t_data		*info;
}				t_philo;

int	init_data(t_philo *p, char **av);

#endif
=======
#endif
=======
#endif
>>>>>>> 47bc9a18e591aa944e49062ae9faa0f93227deac
>>>>>>> 84b520632d6e493ea0ed56d98c70a623d7109ca1
