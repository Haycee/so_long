/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:57:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/01 22:05:28 by alex             ###   ########lyon.fr   */
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
	int		width;
	int		height;
	int		x;
	int		y;
} t_win;

typedef struct s_sprites 
{
	int		size;
	int		state;
	void	*rupee;
	void	*down_idle;
	void	*down_2;
	void	*down_3;
	void	*enemy;
	void	*enemy_2;	
	void	*exit;
	void	*grass;
	void	*grass_2;
	void	*grass_3;
	void	*grass_4;
	void	*grass_5;
	void	*grass_6;
	void	*leaf;
	void	*left_idle;
	void	*left_2;
	void	*left_3;
	void	*left_4;
	void	*plant;
	void	*right_idle;
	void	*right_2;
	void	*right_3;
	void	*right_4;
	void	*stone;
	void	*up_idle;
	void	*up_2;
	void	*up_3;
} t_sprites;

typedef struct s_player 
{
	int		is_mooving;
	int		rupees;
	void	*sprite;
	int		steps;
	int		x;
	int		y;
} t_player;

typedef struct s_camera
{
	int		x;
	int		y;
} t_camera;

typedef struct s_data
{
	t_camera	camera;
	t_map		map;
	t_player	player;
	t_sprites	sprites;
	t_win		win;
} t_data;


/* so_long_utils.c */

int		close_file(int fd);
int		open_file(char *argv);
int		randomize(void);


/* initialization.c */

void	camera_ini(t_data *data);
void	player_ini(t_map *map, t_player *player);
void	sprites_ini(t_sprites *sprites, t_win *win);
void	sprites_ini_2(t_sprites *sprites, t_win *win);
void	sprites_ini_3(t_sprites *sprites, t_win *win);


/* map_parser.c */

int		check_borders(t_map *map);
int		check_chars(t_map *map);
int		is_rectangular(t_map *map);
int		parse_map(t_map *map);


/* map_render.c */

void	create_window(t_win *win, t_map *map);
void	customize_map(t_map *map);
void	render_map(t_data *data);


/* map_render_utils.c */

void	change_char(t_map *map, int x, int y);
void    display_player(t_data *data, int x, int y);
void	select_sprite(t_data *data, int x, int y);
void	select_sprite_2(t_data *data, int x, int y);


/* hook.c */

int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
int		set_animation_state(t_data *data);


/* player.c */

void	move_down(t_map *map, t_player *player, t_sprites *sprites);
void	move_left(t_map *map, t_player *player, t_sprites *sprites);
void	move_right(t_map *map, t_player *player, t_sprites *sprite);
void	move_up(t_map *map, t_player *player, t_sprites *sprites);

#endif
