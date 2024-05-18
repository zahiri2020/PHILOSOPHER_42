/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:11:46 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/18 16:11:47 by ezahiri          ###   ########.fr       */
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
			ft_putstr_fd("->invalid argument\n", 2);
			return (-1);
		}
		i++;
	}
	if (a == 1 && (ft_atoi(s) == 0 || ft_atoi(s) > 200))
	{
		ft_putstr_fd("nombre of philo invalid\n", 2);
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

int	main(int ac, char **av)
{
	parse(av, ac);
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
