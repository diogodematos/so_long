/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:50:14 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/03/28 16:50:18 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_double(t_stack *stack_a)
{
	int	a;
	int	b;
	int	check;

	a = 0;
	check = 0;
	while (a < stack_a->size)
	{
		b = a + 1;
		while (b < stack_a->size)
		{
			if (stack_a->stack[a] == stack_a->stack[b])
			{
				write(2, "Error\n", 6);
				check += 1;
				return (check);
			}
			b++;
		}
		a++;
	}
	return (check);
}

int	ft_check_intmax2(char **argv)
{
	static int		a;
	static int		check;
	char			**num;

	num = ft_split(argv[1], ' ');
	while (num[a])
	{
		if (ft_atol(num[a]) > 2147483647)
		{
			write(2, "Error\n", 6);
			check += 1;
			while (num[a])
			{
				free(num[a]);
				a++;
			}
			free(num);
			return (check);
		}
		free(num[a]);
		a++;
	}
	free(num);
	return (check);
}

int	ft_check_error2(t_stack *stack_a, char **argv)
{
	static int	check;

	if (ft_check_double(stack_a) == 1)
	{
		check += 1;
		return (check);
	}
	else if (ft_check_intmax2(argv) == 1)
	{
		check += 1;
		return (check);
	}
	return (check);
}
