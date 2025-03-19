/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:36:13 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/02/06 13:36:17 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	a = stack_a->size;
	while (a > 0)
	{
		stack_a->stack[a] = stack_a->stack[a - 1];
		a--;
	}
	stack_a->stack[a] = stack_b->stack[a];
	stack_a->size += 1;
	stack_a->max += 1;
	a = 0;
	stack_b->size -= 1;
	while (a < stack_b->size)
	{
		stack_b->stack[a] = stack_b->stack[a + 1];
		a++;
	}
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	a = stack_b->size;
	while (a > 0)
	{
		stack_b->stack[a] = stack_b->stack[a - 1];
		a--;
	}
	stack_b->stack[a] = stack_a->stack[a];
	stack_b->size += 1;
	a = 0;
	stack_a->size -= 1;
	stack_a->max -= 1;
	while (a < stack_a->size)
	{
		stack_a->stack[a] = stack_a->stack[a + 1];
		a++;
	}
	ft_printf("pb\n");
}
