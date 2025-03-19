/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:54:46 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/26 17:15:38 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(void)
{
	int	i;

	i = 0;
	while (i < map()->height)
	{
		if (map()->map)
			free(map()->map[i]);
		if (map()->map_copy)
			free(map()->map_copy[i]);
		i++;
	}
	free(map()->map);
	if (map()->map_copy)
		free(map()->map_copy);
}
