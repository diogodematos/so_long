/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:00:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/02/16 17:00:30 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rra(t_stack *stack)
{
	int	a;
	int	tmp;

	a = stack->size - 1;
	tmp = stack->stack[a];
	while (a > 0)
	{
		stack->stack[a] = stack->stack[a - 1];
		a--;
	}
	stack->stack[a] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	a;
	int	tmp;

	a = stack->size - 1;
	tmp = stack->stack[a];
	while (a > 0)
	{
		stack->stack[a] = stack->stack[a - 1];
		a--;
	}
	stack->stack[a] = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stacka, t_stack *stackb)
{
	rra(stacka);
	rrb(stackb);
}
