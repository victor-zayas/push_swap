/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:29:17 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/02 17:34:51 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	void	check_dupl(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = control->stack_a;
	stack = control->stack_a;
	while (stack)
	{
		aux = stack;
		j = i;
		while (aux)
		{
			if (aux->content == stack->content && i != j)
				control->error = 1;
			aux = aux->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
}

int	check_order(int nb, t_control *control)
{
	int		i;
	t_list	*stack;

	i = 0;
	stack = control->stack_a;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			i++;
		stack = stack->next;
	}
	if (nb == 0 && i == 0 && control->error == 0)
		control->error = 2;
	if (nb == 1 && i == 0)
		return (0);
	return (1);
}

void	check_error(t_control *control)
{
	if (control->error == 1)
	{
		free_lst(&control->stack_a);
		write(2, "Error\n", 6);
		exit(0);
	}
	if (control->error == 2)
	{
		free_lst(&control->stack_a);
		exit(0);
	}
	if (control->error == 3)
		exit(0);
}

void	check_input(t_control *control)
{
	int	i;

	if (control->error == 0)
	{
		i = ft_lstsize(control->stack_a);
		if (i == 0)
			control->error = 3;
		else if (i > 0)
		{
			check_dupl(control);
			check_order(0, control);
		}
	}
	check_error(control);
}
