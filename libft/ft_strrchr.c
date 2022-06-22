/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:48:33 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/04/07 12:48:33 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	d;

	d = c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == d)
			return ((char *)&str[i]);
		--i;
	}
	return (0);
}
