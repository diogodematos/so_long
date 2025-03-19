/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pssplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:21 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/03/21 21:35:42 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(char const *str, char c)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (str[a])
	{
		if (str[a] != c)
			i++;
		a++;
	}
	return (i);
}

void	ft_pssplit(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	char	**num;
	int		a;

	num = ft_split(argv[1], ' ');
	a = 0;
	stack_a->stack = ft_calloc(count_size(argv[1], ' '), sizeof(int));
	stack_b->stack = ft_calloc(count_size(argv[1], ' '), sizeof(int));
	stack_b->size = 0;
	while (num[a])
	{
		stack_a->stack[a] = ft_atoi(num[a]);
		free(num[a]);
		a++;
	}
	stack_a->size = a;
	stack_a->max = a - 1;
	free(num);
}
