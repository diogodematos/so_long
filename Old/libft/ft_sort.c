/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:27:35 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/03/30 15:27:37 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort2(t_stack *stack_a)
{
	sa(stack_a);
}

void	ft_sort3(t_stack *stack_a)
{
	int	a;

	a = 0;
	if (ft_check_order(stack_a) == 0)
	{
		if ((stack_a->stack[a] > stack_a->stack[a + 1])
			&& (stack_a->stack[a] > stack_a->stack[stack_a->max]))
			ra(stack_a);
		else if ((stack_a->stack[a] > stack_a->stack[a + 1])
			&& (stack_a->stack[a] < stack_a->stack[stack_a->max]))
			sa(stack_a);
		else if ((stack_a->stack[a] < stack_a->stack[a + 1])
			&& (stack_a->stack[a] > stack_a->stack[stack_a->max]))
			rra(stack_a);
		else if ((stack_a->stack[a] < stack_a->stack[a + 1])
			&& (stack_a->stack[a] < stack_a->stack[stack_a->max])
			&& (ft_check_order(stack_a) == 0))
			rra(stack_a);
		return (ft_sort3(stack_a));
	}
}

void	ft_sort5(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	a = 0;
	if ((ft_check_order(stack_a) == 0)
		|| (ft_check_order(stack_a) == 1 && stack_b->size != 0))
	{
		if ((stack_a->stack[a] > stack_a->stack[a + 1])
			&& (stack_a->stack[a] > stack_a->stack[stack_a->max]))
			ra(stack_a);
		else if ((stack_a->stack[a] > stack_a->stack[a + 1])
			&& (stack_a->stack[a] < stack_a->stack[stack_a->max]))
			sa(stack_a);
		else if ((stack_a->stack[a] < stack_a->stack[a + 1])
			&& (stack_a->stack[a] > stack_a->stack[stack_a->max]))
			rra(stack_a);
		else if ((stack_a->stack[a] < stack_a->stack[a + 1])
			&& (stack_a->stack[a] < stack_a->stack[stack_a->max])
			&& (ft_check_order(stack_a) == 0))
			pb(stack_a, stack_b);
		else if ((ft_check_order2(stack_b) == 0) && stack_b->size > 1)
			sb(stack_b);
		else if (ft_check_order(stack_a) == 1 && stack_b->size != 0)
			pa(stack_a, stack_b);
		return (ft_sort5(stack_a, stack_b));
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		ft_sort2(stack_a);
	else if (stack_a->size == 3)
		ft_sort3(stack_a);
	else if (stack_a->size == 5)
		ft_sort5(stack_a, stack_b);
	else
	{
		ft_index(stack_a);
		ft_sortall(stack_a, stack_b);
	}
	ft_free(stack_a, stack_b);
}
