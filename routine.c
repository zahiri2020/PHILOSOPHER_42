/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:25:15 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/22 22:36:37 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *p)
{
	char	*s1;
	char	*s2;

	s1 = "has taken a fork";
	s2 = " is eating";
	pthread_mutex_lock (p->right_fork);
	printf ("%lld  %d %s \n", get_time() - p->info->t_start, p->id, s1);
	pthread_mutex_lock (p->left_fork);
	printf ("%lld  %d %s \n", get_time() - p->info->t_start, p->id, s1);
	printf ("%lld  %d %s \n", get_time() - p->info->t_start, p->id, s2);
	ft_sleep (p->info->t_eat);
	pthread_mutex_unlock (p->right_fork);
	pthread_mutex_unlock (p->left_fork);
}

void	sleeping(t_philo *p)
{
	char	*s;

	s = "is sleeping";
	ft_sleep (p->info->t_sleep);
	printf ("%lld  %d %s \n", get_time() - p->info->t_start, p->id, s);
}

void	thinking(t_philo *p)
{
	char	*s;

	s = " is thinking";
	printf ("%lld  %d %s \n", get_time() - p->info->t_start, p->id, s);
}