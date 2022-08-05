/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:19 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/04 15:07:58 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_lst(t_list *stack)
{
	while (stack)
	{
		printf("%d	->	%d,	", stack->index, stack->content);
		printf("%d ra,	%d rb,	%d rr	", stack->ra, stack->rb, stack->rr);
		printf("%d rra,	%d rrb,	%d rrr ", stack->rra, stack->rrb, stack->rrr);
		printf("Total moves -> %d\n", stack->moves);
		stack = stack->next;
	}
}

void	print_struc(t_control *control)
{
	write(1, "\n--- Stack a ---\n", 18);
	print_lst(control->stack_a);
	write(1, "\n--- Stack b ---\n", 18);
	print_lst(control->stack_b);
}
