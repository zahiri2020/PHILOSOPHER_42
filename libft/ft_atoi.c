/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:51:47 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/19 15:29:59 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	r;
	int		s;

	r = 0;
	s = 1;
	if (!str)
		return (-1);
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		if ((r > 2147483647 && s == 1) || (r > 2147483648 && s == -1))
			return (-1);
		str++;
	}
	return (r * s);
}
