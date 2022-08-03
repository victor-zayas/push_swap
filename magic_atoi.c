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

int long	ft_atoi(const char *str, int *error)
{
	int	i;
	int	sign;
	int	nb;

	ft_cmp(str);
	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			*error = 1;
		nb = (nb * 10) + (str[i++] - '0');
	}
	return (nb * sign);
}
