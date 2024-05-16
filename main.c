/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:11:46 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/16 15:11:21 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (0);
}

void	parse(char **av, int ac)
{
	int	i;

	i = 0;
	if (ac == 6 || ac == 5)
	{
		while (av[++i])
			if (check(av[i]) == -1)
				exit(write(1 ,"invalid argment\n", 17));
	}
	else
		exit(write (1, "ERROR in nombre of argument\n", 29));
}

int	main(int ac, char **av)
{
	parse(av, ac);
}