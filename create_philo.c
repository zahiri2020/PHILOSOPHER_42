/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:25:32 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/31 10:47:39 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_f(void *data)
{
	t_philo	*p;
	long	t;
	int		flag;

	p =	(t_philo *)data;
	while (1)
	{
		pthread_mutex_lock (&p->info->data_s);
		t = p->info->t_start;
		pthread_mutex_unlock (&p->info->data_s);
		if (t)
			break ;
	}
	pthread_mutex_lock (&p->philo_s);
	p->last_eat = get_time();
	pthread_mutex_unlock (&p->philo_s);
	if (p->id % 2 == 1)
		ft_sleep(p->info->t_eat, p);
	if (p->info->n_mails < 0)
	{
		while (1)
		{
			pthread_mutex_lock (&p->info->data_s);
			flag = p->info->flag;
			pthread_mutex_unlock (&p->info->data_s);
			if (flag == 1)
				break ;
			eating (p);
			sleeping (p);
			thinking(p);
		}
	}
	return (NULL);
}

int	create_philo(t_philo *p)
{
	int		i;
	int		j;
	long	t;

	i = -1;
	char *s = "died";
	p->info->t_start = 0;
	while (++i < p->info->n_philo)
		if (0 != pthread_create(&(p + i)->philo, NULL, philo_f, p + i))
			return (free(p->info->forks), free(p->info), free(p), -1);
	pthread_mutex_lock (&p->info->data_s);
	p->info->t_start = get_time();
	pthread_mutex_unlock (&p->info->data_s);
	ft_sleep(p->info->t_dead, p);
	while (1)
	{
		i = 0;
		while (i < p->info->n_philo)
		{
			j = 0;
			pthread_mutex_lock (&(p + i)->philo_s);
			t = (p + i)->last_eat;
			pthread_mutex_unlock (&(p + i)->philo_s);
			if (get_time() - t >= (p + i)->info->t_dead)
			{
				pthread_mutex_lock (&p->info->data_s);
				p->info->flag = 1;
				pthread_mutex_unlock (&p->info->data_s);
				while (j < p->info->n_philo)
				{
					// (p + j)->info->flag = 1;
					pthread_join((p + j++)->philo, NULL);
				}
				printf ("%lld\t%d\t%s\n", get_time() - (p + i)->info->t_start, p->id, s);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
