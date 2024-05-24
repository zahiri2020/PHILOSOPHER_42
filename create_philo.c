/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:25:32 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/24 22:53:39 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_f(void *data)
{
	t_philo	*p;

	p =	(t_philo *)data;
	while (!p->info->t_start)
		;
	if (p->id % 2 == 0)
		ft_sleep(p->info->t_eat / 2);
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
	char *s= "is died";
	p->info->t_start = 0;
	while (++i < p->info->n_philo)
		if (0 != pthread_create(&(p + i)->philo, NULL, philo_f, p + i))
			return (free(p->info->forks), free(p->info), free(p), -1);
	p->info->t_start = get_time();
	ft_sleep(p->info->t_dead);
	while (1)
	{
		i = 0;
		while (i < p->info->n_philo)
		{
			if (get_time() - (p + i)->last_eat >= (p + i)->info->t_dead)
			{
				printf ("%lld  %d %s \n", get_time() - (p + i)->info->t_start, p->id, s);
				return (1);
			}
			i++;
		}
	}
	return (0);
}