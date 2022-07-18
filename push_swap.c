/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:30:11 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/07/18 13:47:32 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_nonum(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i][j])
	{
		j = 0;
		while (array[i][j])
		{
			printf("i:%dj:%darray:%c\n", i, j, array[i][j]);
			if (!ft_isdigit(array[i][j]))
			{
				write(1, "Error Num\n", 10);
				exit (1);
			}
		j++;
		}
	i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**array;
	char	c;

	c = ' ';
	i = 0;
	if (argc > 1)
	{
		array = ft_split(argv[1], c);
		if (array == NULL)
			exit (1);
		ft_nonum(array);
		if (ft_atoi(array[i]) > INT_MAX)
		{
			write(1, "Error INT_MAX\n", 14);
			exit (1);
		}
		while (array[i])
		{
			printf("%ld\n", ft_atoi(array[i]));
			i++;
		}
	}
}
