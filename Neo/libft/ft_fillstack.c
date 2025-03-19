/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:10:12 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/03/22 12:10:14 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fillstack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	int	num;
	int	a;

	num = 0;
	a = 0;
	stack_a->stack = ft_calloc((argc - 1), sizeof(int));
	stack_b->stack = ft_calloc((argc - 1), sizeof(int));
	stack_a->size = argc - 1;
	stack_a->max = argc - 2;
	stack_b->size = 0;
	while (a < stack_a->size)
	{
		num = ft_atoi(argv[a + 1]);
		stack_a->stack[a] = num;
		a++;
	}
}
