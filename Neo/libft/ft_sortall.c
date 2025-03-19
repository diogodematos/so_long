/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:03:02 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/04/25 15:03:04 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_b(t_stack *stack_a, t_stack *stack_b, int shift)
{
	int	a;
	int	size;

	if (ft_check_order2(stack_b) && ft_check_order(stack_a))
	{
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		return ;
	}
	size = stack_b->size;
	a = 0;
	while (a < size)
	{
		if ((stack_b->stack[0] & (1 << (shift + 1))) == 0)
			rb(stack_b);
		else
			pa(stack_a, stack_b);
		a++;
	}
}

void	ft_sortall(t_stack *stack_a, t_stack *stack_b)
{
	static int	a;
	static int	max_bits;
	int			b;
	int			size;

	size = stack_a->size;
	while ((stack_a->max >> max_bits) != 0)
		++max_bits;
	while (a < max_bits)
	{
		size = stack_a->size;
		b = 0;
		while (b < size && (ft_check_order(stack_a) == 0))
		{
			if (((stack_a->stack[0] >> a) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			b++;
		}
		sort_b(stack_a, stack_b, a);
		a++;
	}
}
