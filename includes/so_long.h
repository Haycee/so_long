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
	int		height;
	int		width;
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
	void	*player;
	void	*enemy;
	void	*grass;
	void	*grass_2;
	void	*grass_3;
	void	*grass_4;
	void	*tree;
	void	*rock;
	void	*ham;
	int		size;
} t_sprites;

typedef struct s_player 
{
	int		x;
	int		y;
	int		steps;
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
	t_sprites	sprites;
	t_player	player;
	t_camera	camera;
} t_data;


/* so_long_utils.c */

void	sprites_ini(t_sprites *sprites, t_win *win);
int		open_file(char *argv);
int		close_file(int fd);
int		check_event(t_map *map, t_player *player);
int	myrandom(void);

/* map_parser.c */

int	parse_map(t_map *map);
int	check_chars(t_map *map);
int	check_borders(t_map *map);
int	is_rectangular(t_map *map);

/* map_render.c */

void	create_window(t_win *win, t_map *map);
void	select_sprite(t_data *data, int x, int y);
// void	render_map(t_data *data);
void	camera_player(t_data *data);
void	modify_map(t_map *map);

/* key.c */

void	player_ini(t_map *map, t_player *player);
int		get_key(int key, t_data *data);

/* player.c */

void	move_up(t_map *map, t_player *player, t_sprites *sprites, t_win *win);
void	move_left(t_map *map, t_player *player, t_sprites *sprites, t_win *win);
void	move_down(t_map *map, t_player *player, t_sprites *sprites, t_win *win);
void	move_right(t_map *map, t_player *player, t_sprites *sprites, t_win *win);

#endif
