/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/19 09:07:41 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map->map[i] = NULL;
	close(fd);
	return (map->map);
}

char	**ft_mapcheck(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map->map_check = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_check)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map_check[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map->map_check[i] = NULL;
	close(fd);
	return (map->map_check);
}

int	ft_checklineobj(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkmap(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("%s", "Error\nInvalid file\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->width = ft_strlen(line) - 1;
		if (map->width == 0)
			j = 1;
		if (ft_checklineobj(line) == 1)
			j = 2;
		map->height++;
		free(line);
	}
	close(fd);
	return (j);
}

int	ft_check(char **argv, t_map *map)
{
	int	i;

	i = ft_checkmap(argv, map);
	if (i == 0)
	{
		map->map = ft_map(argv, map);
		map->map_check = ft_mapcheck(argv, map);
		if (ft_checkmap2(map) == 1)
		{
			if (ft_checkmap3(map) == 1)
				return (1);
		}
	}
	if (i == 1)
		ft_printf("%s", "Error\nInvalid map\n");
	if (i == 2)
		ft_printf("%s", "Error\nInvalid object in map\n");
	return (0);
}
