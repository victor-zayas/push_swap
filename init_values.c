/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:08:45 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/08 15:44:36 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//Inicio del Index//
void	init_values(int mod, t_control *control)
{
	if (mod == 0)
	{
		control->stack_a = NULL;
		control->a_size = 0;
		control->a_moves = 0;
		control->stack_b = NULL;
		control->b_size = 0;
		control->error = 0;
		control->index_count = 1;
		control->total_moves = 0;
	}
	control->ra = 0;
	control->rb = 0;
	control->rr = 0;
	control->rra = 0;
	control->rrb = 0;
	control->rrr = 0;
}

void	init_stack(int mod, t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while (aux)
	{
		if (mod == 0)
			aux->index = 0;
		aux->ra = 0;
		aux->rb = 0;
		aux->rr = 0;
		aux->rra = 0;
		aux->rrb = 0;
		aux->rrr = 0;
		aux->moves = 0;
		aux = aux->next;
	}
}
