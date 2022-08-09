/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:59:20 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/04 11:30:57 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//Sort 3 numbers algorithm//
void	sort_three(t_control *stk)
{
	if (stk->stack_a->content < stk->stack_a->next->content)
	{
		if (stk->stack_a->content < stk->stack_a->next->next->content)
		{
			rrotate(stk, 'a');
			swap(stk, 'a');
		}
		else
			rrotate(stk, 'a');
	}
	else
	{
		if (stk->stack_a->content < stk->stack_a->next->next->content)
			swap(stk, 'a');
		else
		{
			if (stk->stack_a->next->next->content < stk->stack_a->next->content)
			{
				swap(stk, 'a');
				rrotate(stk, 'a');
			}
			else
				rotate(stk, 'a');
		}
	}
}

static void	push_min(t_control *control)
{
	if (control->a_moves < 3)
		while (control->a_moves--)
			rotate(control, 'a');
	else
	{
		if (control->a_moves == control->a_size - 2)
		{
			rrotate(control, 'a');
			rrotate(control, 'a');
		}
		if (control->a_moves == control->a_size - 1)
			rrotate(control, 'a');
	}
	control->a_moves = 0;
	push(control, 'b');
}

static void	find_min(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		check;
	int		moves;

	stack = control->stack_a;
	moves = 0;
	while (stack)
	{
		check = 0;
		aux = control->stack_a;
		while (aux)
		{
			if (stack->content > aux->content)
				check = 1;
			aux = aux->next;
		}
		if (check == 0)
		{
			control->a_moves = moves;
			break ;
		}
		stack = stack->next;
		moves++;
	}
}

//Sort 5 numbers algorithm//
void	sort_five(t_control *stk)
{
	find_min(stk);
	push_min(stk);
	find_min(stk);
	push_min(stk);
	if (check_order(1, stk))
		sort_three(stk);
	push(stk, 'a');
	push(stk, 'a');
}
