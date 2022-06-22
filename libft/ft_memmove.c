/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:47:11 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/04/07 12:47:11 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_t;
	unsigned char	*src_t;
	size_t			i;

	dst_t = (unsigned char *)dst;
	src_t = (unsigned char *)src;
	i = -1;
	if (dst_t || src_t)
	{
		if (dst_t > src_t)
		{
			while (len--)
				dst_t[len] = src_t[len];
		}
		else
		{
			while (++i < len)
				dst_t[i] = src_t[i];
		}
		return (dst);
	}
	return (NULL);
}
