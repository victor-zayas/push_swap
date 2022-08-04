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

static int	ft_cmp(const char *str)
{
	if (str == NULL)
		return (0);
	return (1);
}

int	ft_atoi(const char *str, int *error)
{
	int		i;
	int		sign;
	long	nb;

	ft_cmp(str);
	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			*error = 1;
		nb = (nb * 10) + (str[i++] - '0');
	}
	if ((nb * sign) < INT_MIN || (nb * sign) > INT_MAX)
		*error = 1;
	return (nb * sign);
}
