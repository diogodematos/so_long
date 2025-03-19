/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:59:17 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/02/16 16:59:33 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra(t_stack *stack)
{
	int	a;
	int	tmp;

	a = 0;
	tmp = stack->stack[a];
	while (a < stack->size - 1)
	{
		stack->stack[a] = stack->stack[a + 1];
		a++;
	}
	stack->stack[a] = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	a;
	int	tmp;

	a = 0;
	tmp = stack->stack[a];
	while (a < stack->size - 1)
	{
		stack->stack[a] = stack->stack[a + 1];
		a++;
	}
	stack->stack[a] = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	ra(stacka);
	rb(stackb);
}
