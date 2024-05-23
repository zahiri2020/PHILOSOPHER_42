/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:34:40 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/22 22:54:06 by ezahiri          ###   ########.fr       */
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
	}
}
// int main ()
// {
// 	ft_sleep(200);
// }