/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:57:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/08 19:20:50 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PATH 1
# define TECH 2
# define PARSING 3
# define OPEN_FILE 4
# define CLOSE_FILE 5
# define FOLDER 6

# include "../ft_printf/includes/ft_printf.h"
# include "../mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		end;
	int		exit_count;
	int		player_count;
	int		rupee_count;
	int		height;
	int		width;
	int		x;
	int		y;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_win;

typedef struct s_sprites
{
	int		size;
	int		state;
	void	*rupee;
	void	*purse;
	void	*down_idle;
	void	*down_2;
	void	*down_3;
	void	*enemy_1;
	void	*enemy_2;
	void	*exit;
	void	*fall;
	void	*fall_2;
	void	*fall_3;
	void	*fall_4;
	void	*fall_5;
	void	*fall_6;
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
	void	*loose;
	void	*plant;
	void	*right_idle;
	void	*right_2;
	void	*right_3;
	void	*right_4;
	void	*shoe;
	void	*stone;
	void	*sword;
	void	*up_idle;
	void	*up_2;
	void	*up_3;
	void	*win;
}	t_sprites;

typedef struct s_player
{
	void	*sprite;
	char	orientation;
	int		frame;
	int		frame_fall;
	int		is_mooving;
	int		rupees;
	int		steps;
	int		x;
	int		y;
}	t_player;

typedef struct s_camera
{
	int		x;
	int		y;
}	t_camera;

typedef struct s_data
{
	t_camera	camera;
	t_map		map;
	t_player	player;
	t_sprites	sprites;
	t_win		win;
}	t_data;

/* so_long_utils.c */

void	close_file(int fd);
void	error_handler(int error_type);
void	initialize_all(t_data *data);
int		open_file(char *argv);
int		randomize(void);

/* sprites_initialization.c */

void	sprites_ini(t_sprites *sprites, t_win *win);
void	sprites_ini_2(t_sprites *sprites, t_win *win);
void	sprites_ini_3(t_sprites *sprites, t_win *win);
void	sprites_ini_4(t_sprites *sprites, t_win *win);

/* player_initialization.c */

void	camera_ini(t_data *data);
void	player_ini(t_map *map, t_player *player);

/* map_parser.c */

void	parse_map(t_map *map);
int		check_borders(t_map *map);
int		check_map_elements(t_map *map);
int		is_rectangular(t_map *map);

/* map_render.c */

void	create_window(t_win *win, t_map *map);
void	customize_map(t_map *map);
void	display_player(t_data *data);
void	render_map(t_data *data);

/* map_render_utils.c */

void	change_char(t_map *map, int x, int y);
char	*get_rupee_sentence(t_data *data);

/* sprite */

void	select_sprite(t_data *data);
void	select_sprite_2(t_data *data, int x, int y);
void	select_sprite_3(t_data *data, int x, int y);
void	select_sprite_4(t_data *data, int x, int y);

/* hook.c */

int		check_player_state(t_data *data);
int		close_window(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
int		set_animation_state(t_data *data);

/* player.c */

void	idle_player(t_data *data);
void	move_down(t_map *map, t_player *player, t_sprites *sprites);
void	move_left(t_map *map, t_player *player, t_sprites *sprites);
void	move_right(t_map *map, t_player *player, t_sprites *sprite);
void	move_up(t_map *map, t_player *player, t_sprites *sprites);

/* player_event.c */

void	event_listener(t_data *data);
void	fall(t_data *data);
void	end_it(t_data *data);

#endif
