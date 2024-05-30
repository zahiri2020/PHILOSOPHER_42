/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:25:15 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/30 13:10:07 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *p)
{
	char	*s1;
	char	*s2;
	int		flag;
	
	pthread_mutex_lock (&p->info->data_s);
	flag = p->info->flag;
	pthread_mutex_unlock (&p->info->data_s);
	if (flag == 1)
		return ;
	pthread_mutex_lock (p->right_fork);
	printf ("%lld\t%d\t%s\n", get_time() - p->info->t_start, p->id, "has taken a fork");
	pthread_mutex_lock (p->left_fork);
	printf ("%lld\t%d\t%s\n", get_time() - p->info->t_start, p->id, "has taken a fork");
	printf ("%lld\t%d\t%s\n", get_time() - p->info->t_start, p->id, "is eating");
	pthread_mutex_lock (&p->philo_s);
	p->last_eat = get_time();
	pthread_mutex_unlock (&p->philo_s);
	ft_sleep (p->info->t_eat, p);
	pthread_mutex_unlock (p->right_fork);
	pthread_mutex_unlock (p->left_fork);
}

void	sleeping(t_philo *p)
{
	char	*s;
	int		flag;

	pthread_mutex_lock (&p->info->data_s);
	flag = p->info->flag;
	pthread_mutex_unlock (&p->info->data_s);
	if (flag == 1)
		return ;
	pthread_mutex_lock(&p->info->write);
	printf ("%lld\t%d\t%s\n", get_time() - p->info->t_start, p->id, "is sleeping");
	pthread_mutex_unlock(&p->info->write);
	ft_sleep (p->info->t_sleep, p);
}

void	thinking(t_philo *p)
{
	char	*s;
	int		flag;

	pthread_mutex_lock (&p->info->data_s);
	flag = p->info->flag;
	pthread_mutex_unlock (&p->info->data_s);
	if (flag == 1)
		return ;
	pthread_mutex_lock(&p->info->write);
	printf ("%lld\t%d\t%s\n", get_time() - p->info->t_start, p->id,  "is thinking");
	pthread_mutex_unlock(&p->info->write);
}