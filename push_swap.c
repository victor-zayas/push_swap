/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:30:11 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/07/20 13:52:57 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

t_list	*get_stack(char **args)
{
	int		i;
	int		aux;
	t_list	*stack;
	t_list	*node;

	i = 0;
	aux = 0;
	stack = NULL;
	while (args[i])
	{
		aux = ft_atoi(args[i]);
		node = ft_lstnew(aux);
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

void	check_dupl(t_list *stack)
{
	t_list	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = stack;
	while (stack)
	{
		aux = stack;
		j = i;
		while (aux)
		{
			if (aux->content == stack->content && i != j)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			aux = aux->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**sp_arg;
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		sp_arg = ft_split(argv[1], ' ');
		stack_a = get_stack(sp_arg);
		ft_free(sp_arg);
		check_dupl(stack_a);
		swap_a(stack_a);
		print_list(stack_a);
		ft_free_lst(&stack_a);
	}
	else
	{
		stack_a = get_stack(&argv[1]);
		check_dupl(stack_a);
		swap_a(stack_a);
		print_list(stack_a);
		ft_free_lst(&stack_a);
	}
}
