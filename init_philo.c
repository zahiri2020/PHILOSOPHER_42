/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:58:55 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/23 20:34:04 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *info, t_philo *phils, int i)
{
	pthread_mutex_init(info->forks + i, NULL);
	phils->id  = i + 1;
	phils->info = info;
	phils->right_fork = info->forks + i;
	if (i == info->n_philo - 1)
		phils->left_fork = &info->forks[0];
	else
		phils->left_fork = &info->forks[i + 1];
	return (0);
}

int	init_philo(t_philo *p, char **av)
{
	t_data	*info;
	int		i;

	i = -1;
	info = (t_data *)malloc (sizeof (t_data));
	if (!info)
		return (free(p), -1);
	info->n_philo = ft_atoi (av[1]);
	info->t_dead = ft_atoi(av[2]);
	info->t_eat = ft_atoi (av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->n_mails = ft_atoi(av[5]);
	info->forks = malloc (sizeof (pthread_mutex_t) * info->n_philo);
	if (!info->forks)
		return (free(p), free(info), -1);
	while (++i < info->n_philo)
		init_data(info, &p[i], i);
	create_philo(p);
	return (0);
}

	// i = -1;
	// while (++i < info->n_philo)
	// {
	// 	printf ("%d\n", (p + i)->id);
	// 	printf ("tiem->%lld\n", (p + i)->info->t_start - get_time());
	// }
	// sleep(1);
	// printf ("tiem->%lld\n",(get_time() - (p + i)->info->t_start)  / 1000 );
	// printf ("%p\n", p->info->fork);
	// printf ("%p\n", (*d)->fork);
	// printf ("%p\n", p->info);
	// printf ("%ld\n", p->info->n_mails);
	// printf ("%d\n", p->info->n_philo);
	// printf ("%ld\n", p->info->t_eat);
	// printf ("%ld\n", p->info->t_sleep);
	// printf ("%ld\n", p->info->t_dead);