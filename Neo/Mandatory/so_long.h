/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:15:33 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/26 16:22:20 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./../libft/libft.h"
# include "./../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_map
{
	int		collectible;
	int		wall;
	int		player;
	int		exit;
	int		width;
	int		height;
	int		px;
	int		py;
	int		cc;
	int		ec;
	int		exitx;
	int		exity;
	char	**map;
	char	**map_copy;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	void	*exitwin_img;
	int		hei;
	int		wid;
	void	*mlx;
	void	*mlx_win;
	int		size;
	int		moves;
}								t_map;

t_map	*map(void);
void	setup_map(void);
int		ft_checkber(char **argv);
int		ft_check(char **argv);
int		ft_checkmap(char **argv);
char	**ft_mapcopy(char **argv);
char	**ft_map(char **argv);
int		ft_checkwidth(void);
int		ft_checkobjects(void);
int		ft_checkwalls(void);
int		ft_countobjects(void);
void	ft_checkppos(void);
int		ft_checkpath(int x, int y);
int		ft_startgame(void);
void	ft_showimg();
void	ft_putimg(char element, int x, int y);
int		ft_keypress(int keysym);
int		ft_checkmove(char a, int x, int y);
void	ft_moved(void);
void	ft_movea(void);
void	ft_moves(void);
void	ft_movew(void);
int		ft_game_destroy(void);
void	ft_freemap(void);

#endif
