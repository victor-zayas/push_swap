/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:10:44 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/07/20 14:29:59 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_a(t_list *stack)
{
	int		aux;

	aux = stack->content;
	stack->content = stack->next->content;
	stack->next->content = aux;
}
