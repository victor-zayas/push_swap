/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:25:18 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/08 19:15:20 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//Estructuras//
typedef struct s_control
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	int				a_size;
	int				a_moves;
	int				b_size;
	int				error;
	int				index_count;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total_moves;
}					t_control;

typedef struct s_list
{
	struct s_list	*next;
	int				content;
	int				index;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				moves;
}					t_list;

//Utils libft | magic_atoi/split.c list_utils.c//
int			ft_atoi(const char *str, int *error);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);

//Imprimir stacks | print.c//
void		print_struc(t_control *control);

//Liberar nodos de la lista | free.c//
void		free_lst(t_list **lst);
void		ft_free(char **ptr);

//Control de errores | check.c//
void		check_input(t_control *control);
int			check_order(int nb, t_control *control);

//Creacion del index | index.c//
void		indexsu(t_control *control);

//Movements | movements.c & movements_2.c//
void		swap(t_control *control, char c);
void		push(t_control *control, char c);
void		rotate(t_control *control, char c);
void		rrotate(t_control *control, char c);

//Algorithm | sort_sort.c sort_all.c//
void		sort_three(t_control *stk);
void		sort_five(t_control *stk);
void		sort_all(t_control *control);

//Count moves & optimize | count.c//
void		count_moves_b(t_control *control);
void		count_moves_a(t_control *control);
void		optimize_moves(t_list *stack);

//Start values of strructure | init_values.c//
void		init_values(int mod, t_control *control);
void		init_stack(int mod, t_list *stack);

#endif