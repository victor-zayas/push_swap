/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:12:25 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/03 11:17:08 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_control *control)
{
	t_list	*aux;

	aux = control->stack_a;
	push(control, 'b');
	push(control, 'b');
	count_moves_a(control);
	count_moves_b(control);
	optimize_moves(control->stack_a);
	total_moves(control->stack_a);
}
