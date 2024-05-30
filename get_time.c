/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:34:40 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/30 20:27:19 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	long	get_time(void)
{
	struct timeval	t;

	if (0 != gettimeofday(&t, NULL))
		return (0);
	else
		return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_check(t_philo *p)
{
	int	flag;

	pthread_mutex_lock (&p->info->data_s);
	flag = p->info->flag;
	pthread_mutex_unlock (&p->info->data_s);
	return (flag);
}
void	ft_sleep(int t, t_philo *p)
{
	long long	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= t)
			return ;
		usleep(100);
	}
}
