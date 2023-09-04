/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startgame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:49:45 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/19 09:50:52 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putimg(t_map *map, char element, int x, int y)
{
	if (element == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->wall_img, x * map->size, y * map->size);
	else if (element == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->floor_img, x * map->size, y * map->size);
	else if (element == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->player_img, x * map->size, y * map->size);
	else if (element == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->collectible_img, x * map->size, y * map->size);
	else if (element == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->exit_img, x * map->size, y * map->size);
	else if (element == 'D')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->enemy_img, x * map->size, y * map->size);
}

void	ft_showimg(t_map *map)
{
	int		i;
	int		j;
	char	element;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < (map->width + 1))
		{
			element = map->map[i][j];
			if (map->map[i][j] == '1')
				ft_putimg(map, element, j, i);
			else if (map->map[i][j] == '0')
				ft_putimg(map, element, j, i);
			else if (map->map[i][j] == 'P')
				ft_putimg(map, element, j, i);
			else if (map->map[i][j] == 'C')
				ft_putimg(map, element, j, i);
			else if (map->map[i][j] == 'E')
				ft_putimg(map, element, j, i);
			else if (map->map[i][j] == 'D')
				ft_putimg(map, element, j, i);
		}
	}
}

int	ft_game_destroy(t_map *map)
{
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->player_img);
	mlx_destroy_image(map->mlx, map->collectible_img);
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->exitwin_img);
	mlx_destroy_image(map->mlx, map->floor_img);
	mlx_destroy_image(map->mlx, map->enemy_img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_freemap(map);
	exit(0);
}

int	ft_keypress(int keysym, t_map *map)
{
	if (keysym == 65307)
		ft_game_destroy(map);
	if ((keysym == 119) || (keysym == 65362))
		ft_checkmove(map, keysym, map->px, map->py - 1);
	if ((keysym == 115) || (keysym == 65364))
		ft_checkmove(map, keysym, map->px, map->py + 1);
	if ((keysym == 97) || (keysym == 65361))
		ft_checkmove(map, keysym, map->px - 1, map->py);
	if ((keysym == 100) || (keysym == 65363))
		ft_checkmove(map, keysym, map->px + 1, map->py);
	return (0);
}

int	ft_startgame(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, ((map->width + 1) * map->size),
			(map->height * map->size), "Bananas Slave");
	mlx_string_put(map->mlx, map->mlx_win, 100, 100, 0xFFFFFF, map->counter);
	map->wall_img = mlx_xpm_file_to_image(map->mlx,
			"./textures/wall.xpm", &map->wid, &map->hei);
	map->floor_img = mlx_xpm_file_to_image(map->mlx,
			"./textures/floor.xpm", &map->wid, &map->hei);
	map->player_img = mlx_xpm_file_to_image(map->mlx,
			"./textures/player.xpm", &map->wid, &map->hei);
	map->collectible_img = mlx_xpm_file_to_image(map->mlx,
			"./textures/collectible.xpm", &map->wid, &map->hei);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm",
			&map->wid, &map->hei);
	map->exitwin_img = mlx_xpm_file_to_image(map->mlx, "./textures/exit1.xpm",
			&map->wid, &map->hei);
	map->enemy_img = mlx_xpm_file_to_image(map->mlx, "./textures/enemy.xpm",
			&map->wid, &map->hei);
	ft_showimg(map);
	mlx_hook(map->mlx_win, KeyPress, KeyPressMask, &ft_keypress, map);
	mlx_hook(map->mlx_win, DestroyNotify,
		ButtonPressMask, &ft_game_destroy, map);
	mlx_loop(map->mlx);
	return (0);
}
