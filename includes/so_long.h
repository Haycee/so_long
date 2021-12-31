/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:57:39 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/20 17:38:47 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		c_num;
	int		e_num;
	int		p_num;
	int		width;
	int		height;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		x;
	int		y;
} t_win;

typedef struct s_sprites 
{
	int		size;
	int		state;
	void	*enemy;
	void	*enemy_2;	
	void	*grass;
	void	*grass_2;
	void	*grass_3;
	void	*grass_4;
	void	*grass_5;
	void	*grass_6;
	void	*tree;
	void	*stone;
	void	*collectible;
	void	*left_idle;
	void	*left_2;
	void	*left_3;
	void	*left_4;
	void	*right_idle;
	void	*right_2;
	void	*right_3;
	void	*right_4;
	void	*up_idle;
	void	*up_2;
	void	*up_3;
	void	*down_idle;
	void	*down_2;
	void	*down_3;
} t_sprites;

typedef struct s_player 
{
	int		x;
	int		y;
	int		steps;
	void	*state;
	int		collected;
} t_player;

typedef struct s_camera
{
	int		x;
	int		y;
} t_camera;

typedef struct s_data
{
	t_map		map;
	t_win		win;
	t_player	player;
	t_camera	camera;
	t_sprites	sprites;
} t_data;


/* so_long_utils.c */

int		myrandom(void);
int		open_file(char *argv);
int		close_file(int fd);
void	player_ini(t_map *map, t_player *player);
int		check_event(t_map *map, t_player *player);
void	sprites_ini(t_sprites *sprites, t_win *win);
void	sprites_ini_2(t_sprites *sprites, t_win *win);

/* map_parser.c */

int		parse_map(t_map *map);
int		check_chars(t_map *map);
int		check_borders(t_map *map);
int		is_rectangular(t_map *map);

/* map_render.c */

void	modify_map(t_map *map);
void	create_window(t_win *win, t_map *map);
void	select_sprite(t_data *data, int x, int y);
void	camera_player(t_data *data);

/* key.c */

int		back_anim(t_data *data);
int		get_key(int key, t_data *data);

/* player.c */

int		move_up(t_map *map, t_player *player, t_sprites *sprites, t_win *win);
int		move_left(t_map *map, t_player *player, t_sprites *sprites, t_win *win);
int		move_down(t_map *map, t_player *player, t_sprites *sprites, t_win *win);
int		move_right(t_map *map, t_player *player, t_sprites *sprites, t_win *win);

#endif
