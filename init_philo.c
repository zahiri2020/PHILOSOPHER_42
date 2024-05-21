/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:58:55 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/20 20:58:36 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_philo(t_philo *p, char **av)
{
	int	i;

	i = -1;
	p->info = (t_data *)malloc (sizeof (t_data));
	if (!p->info)
		return (-1);
	p->info->n_philo = ft_atoi (av[1]);
	p->info->t_dead = ft_atoi(av[2]);
	p->info->t_eat = ft_atoi (av[3]);
	p->info->t_sleep = ft_atoi(av[4]);
	p->info->n_mails = ft_atoi(av[5]);
	p->info->fork = malloc (sizeof(pthread_mutex_t) * ((p->info)->n_philo + 1));
	if (!p->info->fork)
		return (-1);
	while (++i < p->info->n_philo)
		pthread_mutex_init(&p->info->fork[i], NULL);
	return (0);
}

	// printf ("%p\n", p->info->fork);
	// printf ("%p\n", (*d)->fork);
	// printf ("%p\n", p->info);
	// printf ("%ld\n", p->info->n_mails);
	// printf ("%d\n", p->info->n_philo);
	// printf ("%ld\n", p->info->t_eat);
	// printf ("%ld\n", p->info->t_sleep);
	// printf ("%ld\n", p->info->t_dead);