/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:45:59 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/04/07 12:45:59 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_atoi(const char *str, int *error)
{
	int		sign;
	int		i;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	if (!str[i])
		*error = 1;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			*error = 1;
		num = num * 10 + (str[i++] - 48);
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
		*error = 1;
	return (num * sign);
}
