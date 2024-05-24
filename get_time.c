/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:34:40 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/23 22:49:34 by ezahiri          ###   ########.fr       */
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

void	ft_sleep(int t)
{
	long long	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= t)
			return ;
		// usleep(100);
	}
}
// int main ()
// {
// 	ft_sleep(200);
// }