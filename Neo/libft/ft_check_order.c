/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:32 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/03/30 15:11:35 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_order(t_stack *stack_a)
{
	int	check;
	int	a;

	a = stack_a->size - 1;
	check = 0;
	if (stack_a->size == 1)
	{
		check += 1;
		return (check);
	}
	while (a > 0)
	{
		if (stack_a->stack[a] > stack_a->stack[a - 1])
			a--;
		else
			return (check);
	}
	check += 1;
	return (check);
}

int	ft_check_order2(t_stack *stack_b)
{
	int	check;
	int	a;

	a = stack_b->size - 1;
	check = 0;
	if (stack_b->size == 1)
	{
		check += 1;
		return (check);
	}
	while (a > 0)
	{
		if (stack_b->stack[a] < stack_b->stack[a - 1])
			a--;
		else
			return (check);
	}
	check += 1;
	return (check);
}
