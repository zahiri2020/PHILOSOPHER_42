/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmmmm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:00:05 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/30 00:03:33 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *philo_f(void *data)
{
	int	*p;

	p =	(int *)data;
	printf("%d\n", *p);
	return (NULL);
}

int	main()
{
	pthread_t	philo;
	int			i;

	i = 42;
	pthread_create(&philo, NULL, philo_f, &i);
	pthread_create(&philo, NULL, philo_f, &i);
	pthread_join(philo, NULL);
}