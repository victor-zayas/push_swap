/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:15:34 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/03 11:08:23 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	min_index(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		check;

	stack = control->stack_a;
	while (stack)
	{
		check = 0;
		aux = control->stack_a;
		while (aux)
		{
			if (stack->content > aux->content && aux->index == 0)
				check = 1;
			aux = aux->next;
		}
		if (check == 0 && stack->index == 0)
		{
			stack->index = control->index_count++;
			break ;
		}
		stack = stack->next;
	}
}

void	indexsu(t_control *control)
{
	int	i;

	i = control->a_size;
	while (i--)
		min_index(control);
}
