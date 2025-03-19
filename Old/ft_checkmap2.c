/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:52:18 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/16 12:52:22 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countobjects(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->collectible++;
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkwalls(t_map *map)
{
	static int	i;
	static int	j;

	while (j <= map->width)
	{
		if (map->map[0][j] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		if (map->map[map->height -1][j] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		j++;
	}
	while (i < map->height - 1)
	{
		if (map->map[i][0] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		if (map->map[i][map->width] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		i++;
	}
	return (1);
}

int	ft_checkobjects(t_map *map)
{
	if (map->collectible < 1)
		return (ft_printf("%s", "Error\nNo collectibles\n"));
	if (map->exit != 1)
		return (ft_printf("%s", "Error\nNo exit or many exits\n"));
	if (map->player != 1)
		return (ft_printf("%s", "Error\nNo player or many players\n"));
	if (ft_checkwalls(map) != 1)
		return (0);
	return (1);
}

int	ft_checkwidth(t_map *map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (i == 0)
			width = j;
		else if (j != width)
		{
			if (i == map->height -1)
				return (1);
			else
				return (ft_printf("%s", "Error\nMap isn't rectangular\n"));
		}
		i++;
	}
	return (1);
}

int	ft_checkmap2(t_map *map)
{
	ft_countobjects(map);
	if (ft_checkwidth(map) != 1)
		return (0);
	if (ft_checkobjects(map) != 1)
		return (0);
	return (1);
}
