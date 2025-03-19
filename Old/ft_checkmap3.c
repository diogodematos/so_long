/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2025/03/19 17:47:26 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkpath(t_map *map, int x, int y)
{
	if (map->map_check[y][x] == '1' || map->map_check[y][x] == 'X')
		return (1);
	if (map->map_check[y][x] == 'C')
		map->cc++;
	if (map->map_check[y][x] == 'E')
	{
		map->ec++;
		map->map_check[y][x] = 'X';
		return (1);
	}
	map->map_check[y][x] = 'X';
	ft_checkpath(map, x + 1, y);
	ft_checkpath(map, x - 1, y);
	ft_checkpath(map, x, y + 1);
	ft_checkpath(map, x, y - 1);
	return (0);
}

void	ft_checkppos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height -1)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				map->px = x;
				map->py = y;
			}
			if (map->map[y][x] == 'E')
			{
				map->exitx = x;
				map->exity = y;
			}
			x++;
		}
		y++;
	}
}

int	ft_checkmap3(t_map *map)
{
	ft_checkppos(map);
	ft_checkpath(map, map->px, map->py);
	if (map->ec == 1 && map->cc == map->collectible)
		return (1);
	return (ft_printf("%s", "Error\nInvalid Path\n"));
}
