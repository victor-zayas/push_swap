/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:10:44 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/02 17:26:17 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_mv(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	*stack = aux->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	swap(t_control *control, char c)
{
	if (c == 'a')
	{
		swap_mv(&control->stack_a);
		write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		swap_mv(&control->stack_b);
		write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		swap_mv(&control->stack_a);
		swap_mv(&control->stack_b);
		write(1, "ss\n", 3);
	}
}

void	push(t_control *control, char c)
{
	t_list	*aux;

	if (c == 'a')
	{
		aux = control->stack_b;
		control->stack_b = control->stack_b->next;
		ft_lstadd_front(&control->stack_a, aux);
		control->a_size++;
		control->b_size--;
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		aux = control->stack_a;
		control->stack_a = control->stack_a->next;
		ft_lstadd_front(&control->stack_b, aux);
		control->a_size--;
		control->b_size++;
		write(1, "pb\n", 3);
	}
}
