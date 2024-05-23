/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:25:32 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/23 20:33:32 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_f(void *data)
{
	t_philo	*p;

	p =	(t_philo *)data;
	if (p->id % 2 == 0)
		usleep(400000);
	if (p->info->n_mails < 0)
	{
		while (1)
		{
			eating (p);
			sleeping (p);
			thinking(p);
		}
	}
	return (NULL);
}

int	create_philo(t_philo *p)
{
	int	i; 

	i = -1;
	p->info->t_start = get_time();
	while (++i < p->info->n_philo)
		if (0 != pthread_create(&(p + i)->philo, NULL, &philo_f, p + i))
			return (free(p->info->forks), free(p->info), free(p), -1);
	i = 0;
	while (++i < p->info->n_philo)
		if (0 != pthread_join((p + i)->philo, NULL))
			return (free(p->info->forks), free(p->info), free(p), -1);
	return (0);
}