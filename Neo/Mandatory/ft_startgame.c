/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startgame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:49:45 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/25 23:00:31 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putimg(char element, int x, int y)
{
	if (element == '1')
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->wall_img, x * map()->size, y * map()->size);
	else if (element == '0')
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->floor_img, x * map()->size, y * map()->size);
	else if (element == 'P')
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->player_img, x * map()->size, y * map()->size);
	else if (element == 'C')
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->collectible_img, x * map()->size, y * map()->size);
	else if (element == 'E')
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->exit_img, x * map()->size, y * map()->size);
}

void	ft_showimg()
{
	int		i;
	int		j;
	char	element;

	i = -1;
	while (++i < map()->height)
	{
		j = -1;
		while (++j < (map()->width + 1))
		{
			element = map()->map[i][j];
			if (map()->map[i][j] == '1')
				ft_putimg(element, j, i);
			else if (map()->map[i][j] == '0')
				ft_putimg(element, j, i);
			else if (map()->map[i][j] == 'P')
				ft_putimg(element, j, i);
			else if (map()->map[i][j] == 'C')
				ft_putimg(element, j, i);
			else if (map()->map[i][j] == 'E')
				ft_putimg(element, j, i);
		}
	}
}

int	ft_game_destroy(void)
{
	mlx_destroy_image(map()->mlx, map()->wall_img);
	mlx_destroy_image(map()->mlx, map()->player_img);
	mlx_destroy_image(map()->mlx, map()->collectible_img);
	mlx_destroy_image(map()->mlx, map()->exit_img);
	mlx_destroy_image(map()->mlx, map()->exitwin_img);
	mlx_destroy_image(map()->mlx, map()->floor_img);
	mlx_destroy_window(map()->mlx, map()->mlx_win);
	mlx_destroy_display(map()->mlx);
	free(map()->mlx);
	ft_freemap();
	exit(0);
}

int	ft_keypress(int keysym)
{
	if (keysym == 65307)
		ft_game_destroy();
	if (keysym == 119)
		ft_checkmove(keysym, map()->px, map()->py - 1);
	if (keysym == 115)
		ft_checkmove(keysym, map()->px, map()->py + 1);
	if (keysym == 97)
		ft_checkmove(keysym, map()->px - 1, map()->py);
	if (keysym == 100)
		ft_checkmove(keysym, map()->px + 1, map()->py);
	return (0);
}

int	ft_startgame(void)
{
	map()->mlx = mlx_init();
	printf("Welcome to So Long!\n");
	map()->mlx_win = mlx_new_window(map()->mlx, ((map()->width) * map()->size),
			(map()->height * map()->size), "Bananas Slave");
	map()->wall_img = mlx_xpm_file_to_image(map()->mlx,
			"./textures/wall.xpm", &map()->wid, &map()->hei);
	map()->floor_img = mlx_xpm_file_to_image(map()->mlx,
			"./textures/floor.xpm", &map()->wid, &map()->hei);
	map()->player_img = mlx_xpm_file_to_image(map()->mlx,
			"./textures/player.xpm", &map()->wid, &map()->hei);
	map()->collectible_img = mlx_xpm_file_to_image(map()->mlx,
			"./textures/collectible.xpm", &map()->wid, &map()->hei);
	map()->exit_img = mlx_xpm_file_to_image(map()->mlx, "./textures/exit.xpm",
			&map()->wid, &map()->hei);
	map()->exitwin_img = mlx_xpm_file_to_image(map()->mlx, "./textures/exit1.xpm",
			&map()->wid, &map()->hei);
	ft_showimg();
	mlx_hook(map()->mlx_win, KeyPress, KeyPressMask, &ft_keypress, map());
	mlx_hook(map()->mlx_win, DestroyNotify,
		ButtonPressMask, &ft_game_destroy, map());
	mlx_loop(map()->mlx);
	return (0);
}
