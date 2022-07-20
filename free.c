/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:40:17 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/07/19 12:40:21 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list **lst)
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
