/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:11:46 by ezahiri           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/18 16:11:47 by ezahiri          ###   ########.fr       */
=======
/*   Updated: 2024/05/18 10:28:52 by ezahiri          ###   ########.fr       */
>>>>>>> 47bc9a18e591aa944e49062ae9faa0f93227deac
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check(char *s, int a)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
		{
			ft_putstr_fd("invalid argument\n", 2);
			return (-1);
		}
		i++;
	}
	if (a == 1 && (ft_atoi(s) == 0 || ft_atoi(s) > 200))
	{
		ft_putstr_fd("nambre of philo invalid\n", 2);
		return (-1);
	}
	return (0);
}
#include <stdbool.h>
bool 	parse(char **av, int ac)
{
	int	i;
	
	i = 0;
	if (ac == 6 || ac == 5)
	{
		while (av[++i])
			if (check(av[i], i) == -1)
				exit(1);
	}
	else
		exit(1);
}

size_t get_current_time()
{
    struct timeval tv;
	
    if (gettimeofday(&tv, NULL) != 0)
	{
        perror("gettimeofday");
        return (1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void ft_usleep(size_t melli)
{
	size_t time;

	time = get_current_time();
	while (get_current_time() < time + melli)
		;
}

int	main()
{
	printf("%zu\n", get_current_time());
	ft_usleep(200);
	printf("%zu\n", get_current_time());
}

/*
	struct : t_list
		void *content;
		struct s_list	*next;
		struct s_list	*last;
	struct : settings
		-> number of philos
		-> time_to_die
		-> time_to_eat
		-> time_to_sleep
		-> number_of_meals	[optional]
	struct : object
		-> philos
		-> settings
	struct : philo
		-> id
		-> ...
*/
