/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:12:25 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/05 16:42:27 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_moves(t_list *stack)
{
	t_list	*aux;
	int		moves;

	aux = stack;
	moves = INT_MAX;
	while (aux)
	{
		aux->moves = aux->moves + aux->ra;
		aux->moves = aux->moves + aux->rb;
		aux->moves = aux->moves + aux->rr;
		aux->moves = aux->moves + aux->rra;
		aux->moves = aux->moves + aux->rrb;
		aux->moves = aux->moves + aux->rrr;
		if (moves > aux->moves)
			moves = aux->moves;
		aux = aux->next;
	}
	return (moves);
}

static void	save_moves(int move, t_control *control)
{
	t_list	*aux;

	aux = control->stack_a;
	while (move != aux->moves)
		aux = aux->next;
	control->ra = aux->ra;
	control->rb = aux->rb;
	control->rr = aux->rr;
	control->rra = aux->rra;
	control->rrb = aux->rrb;
	control->rrr = aux->rrr;
}

static void	movementt(t_control *control)
{
	while (control->ra--)
		rotate(control, 'a');
	while (control->rb--)
		rotate(control, 'b');
	while (control->rr--)
		rotate(control, 'r');
	while (control->rra--)
		rotate(control, 'a');
	while (control->rrb--)
		rotate(control, 'b');
	while (control->rrr--)
		rotate(control, 'r');
}

static void	refill_stack_a(t_control *control)
{
	t_list	*aux;

	aux = control->stack_b;
	while (aux->index != control->b_size)
	{
		aux = aux->next;
		control->rb++;
	}
	if (control->rb > (control->b_size / 2))
	{
		control->rb = 0;
		while (aux)
		{
			control->rrb++;
		}
	}
	movementt(control);
	while (control->b_size)
		push(control, 'a');
}

void	sort_all(t_control *control)
{
	t_list	*aux;
	int		moves;

	aux = control->stack_a;
	push(control, 'b');
	push(control, 'b');
	while (control->a_size)
	{
		count_moves_a(control);
		count_moves_b(control);
		optimize_moves(control->stack_a);
		moves = total_moves(control->stack_a);
		save_moves(moves, control);
		movementt(control);
		init_stack(1, control->stack_a);
		push(control, 'b');
	}
	init_values(1, control);
	refill_stack_a(control);
}
