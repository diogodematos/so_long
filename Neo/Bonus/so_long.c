/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/26 17:27:36 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkber(char **argv)
{
	static int	a;
	char		*str;
	int			b;

	str = ".ber";
	while (argv[1][a])
	{
		b = 0;
		while (argv[1][a] == str[b])
		{
			a++;
			b++;
			if (argv[1][a] == '\0' && str[b] == '\0')
				return (1);
			else if ((argv[1][a] == '\0' && str[b] != '\0')
				|| (argv[1][a] != '\0' && str[b] == '\0'))
				return (0);
		}
		a++;
	}
	return (0);
}

void	setup_map(void)
{
	ft_bzero(map(), sizeof(t_map));
	map()->map = NULL;
	map()->map_copy = NULL;
	map()->hei = 32;
	map()->wid = 32;
	map()->mlx = NULL;
	map()->mlx_win = NULL;
	map()->size = 64;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("%s", "Error\nInvalid number of arguments\n"));
	if (ft_checkber(argv) == 0)
		return (ft_printf("%s", "Error\nInvalid file extension\n"));
	setup_map();
	if (!ft_check(argv))
		ft_startgame();
	ft_freemap();
	return (0);
}
