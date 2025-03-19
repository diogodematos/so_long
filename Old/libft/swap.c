/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:36:36 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/02/14 11:56:23 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(t_stack *stack)
{
	int	t;
	int	a;

	if (stack->size < 2)
		return ;
	a = 0;
	t = stack->stack[a];
	stack->stack[a] = stack->stack[a + 1];
	stack->stack[a + 1] = t;
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	int	t;
	int	a;

	if (stack->size < 2)
		return ;
	a = 0;
	t = stack->stack[a];
	stack->stack[a] = stack->stack[a + 1];
	stack->stack[a + 1] = t;
	ft_printf("sb\n");
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	sa(stacka);
	sb(stackb);
}
