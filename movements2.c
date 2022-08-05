/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:43:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/05 14:18:22 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate_mv(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	while (aux->next)
		aux = aux->next;
	aux->next = *stack;
	*stack = (*stack)->next;
	aux->next->next = NULL;
}

void	rotate(t_control *control, char c)
{
	if (c == 'a')
	{
		rotate_mv(&control->stack_a);
		write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		rotate_mv(&control->stack_b);
		write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		rotate_mv(&control->stack_a);
		rotate_mv(&control->stack_b);
		write(1, "rr\n", 3);
	}
}

void	rrotate_mv(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	while (aux->next->next)
		aux = aux->next;
	aux->next->next = *stack;
	*stack = (*stack)->next;
	aux->next->next = NULL;
}

void	rrotate(t_control *control, char c)
{
	if (c == 'a')
	{
		rrotate_mv(&control->stack_a);
		write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		rotate_mv(&control->stack_b);
		write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{
		rotate_mv(&control->stack_a);
		rotate_mv(&control->stack_b);
		write(1, "rrr\n", 4);
	}
}
