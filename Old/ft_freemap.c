/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:54:46 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/06/12 11:54:50 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map)
			free(map->map[i]);
		if (map->map_check)
			free(map->map_check[i]);
		i++;
	}
	free(map->map);
	if (map->map_check)
		free(map->map_check);
}
