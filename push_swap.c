/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:30:11 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/08 16:11:52 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <unistd.h>

//Crear stack//
t_list	*get_stack(char **args, t_control *control)
{
	int		i;
	int		aux;
	t_list	*stack;

	i = 0;
	aux = 0;
	stack = NULL;
	while (args[i])
	{
		aux = ft_atoi(args[i], &control->error);
		ft_lstadd_back(&stack, ft_lstnew(aux));
		i++;
	}
	init_stack(0, stack);
	control->a_size = i;
	return (stack);
}

//Seleccion  de algoritmo//
static void	push_swap(t_control *control)
{
	if (control->a_size == 3)
		sort_three(control);
	else if (control->a_size == 5)
		sort_five(control);
	else
		sort_all(control);
}

int	main(int argc, char **argv)
{
	char		**sp_arg;
	t_control	control;

	init_values(0, &control);
	if (argc == 1)
		control.error = 3;
	else
	{
		if (argc == 2)
		{
			sp_arg = ft_split(argv[1], ' ');
			control.stack_a = get_stack(sp_arg, &control);
			ft_free(sp_arg);
		}
		else
			control.stack_a = get_stack(&argv[1], &control);
	}
	check_input(&control);
	indexsu(&control);
	push_swap(&control);
	//print_struc(&control);
	free_lst(&control.stack_a);
	free_lst(&control.stack_b);
}
