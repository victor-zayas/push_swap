/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:30:11 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/05 14:20:10 by vzayas-s         ###   ########.fr       */
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
		printf("je je je, no esta hecho <3");
		//sort_all(control);
}

//Inicio del Index//
static void	init_values(t_control *control)
{
	control->stack_a = NULL;
	control->a_size = 0;
	control->a_moves = 0;
	control->stack_b = NULL;
	control->b_size = 0;
	control->b_moves = 0;
	control->error = 0;
	control->index_count = 1;
}

int	main(int argc, char **argv)
{
	char		**sp_arg;
	t_control	control;

	init_values(&control);
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
	print_struc(&control);
	free_lst(&control.stack_a);
	free_lst(&control.stack_b);
}
