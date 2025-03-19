/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:21:55 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/06/12 12:21:57 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movew(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = '0';
	map()->py--;
	if (map()->map[map()->py][map()->px] == 'C')
	{
		map()->collectible--;
		if (map()->collectible == 0)
			mlx_put_image_to_window(map()->mlx, map()->mlx_win, map()->exitwin_img,
				map()->exitx * map()->size, map()->exity * map()->size);
	}
	if (map()->map[map()->py][map()->px] == 'E')
	{
		map()->moves++;
		ft_printf("Player Moves: %d\nYou Win!\n", map()->moves);
		ft_game_destroy();
	}
	map()->map[map()->py][map()->px] = 'P';
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_img, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

void	ft_moves(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = '0';
	map()->py++;
	if (map()->map[map()->py][map()->px] == 'C')
	{
		map()->collectible--;
		if (map()->collectible == 0)
			mlx_put_image_to_window(map()->mlx, map()->mlx_win, map()->exitwin_img,
				map()->exitx * map()->size, map()->exity * map()->size);
	}
	if (map()->map[map()->py][map()->px] == 'E')
	{
		map()->moves++;
		ft_printf("Player Moves: %d\nYou Win!\n", map()->moves);
		ft_game_destroy();
	}
	map()->map[map()->py][map()->px] = 'P';
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_img, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

void	ft_movea(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = '0';
	map()->px--;
	if (map()->map[map()->py][map()->px] == 'C')
	{
		map()->collectible--;
		if (map()->collectible == 0)
			mlx_put_image_to_window(map()->mlx, map()->mlx_win, map()->exitwin_img,
				map()->exitx * map()->size, map()->exity * map()->size);
	}
	if (map()->map[map()->py][map()->px] == 'E')
	{
		map()->moves++;
		ft_printf("Player Moves: %d\nYou Win!\n", map()->moves);
		ft_game_destroy();
	}
	map()->map[map()->py][map()->px] = 'P';
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_img, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

void	ft_moved(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = '0';
	map()->px++;
	if (map()->map[map()->py][map()->px] == 'C')
	{
		map()->collectible--;
		if (map()->collectible == 0)
			mlx_put_image_to_window(map()->mlx, map()->mlx_win, map()->exitwin_img,
				map()->exitx * map()->size, map()->exity * map()->size);
	}
	if (map()->map[map()->py][map()->px] == 'E')
	{
		map()->moves++;
		ft_printf("Player Moves: %d\nYou Win!\n", map()->moves);
		ft_game_destroy();
	}
	map()->map[map()->py][map()->px] = 'P';
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_img, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

int	ft_checkmove(char a, int x, int y)
{
	if (map()->map[y][x] == '1')
		return (0);
	if (map()->map[y][x] == 'E' && map()->collectible != 0)
		return (0);
	if (a == 'w')
		ft_movew();
	if (a == 's')
		ft_moves();
	if (a == 'a')
		ft_movea();
	if (a == 'd')
		ft_moved();
	return (1);
}
