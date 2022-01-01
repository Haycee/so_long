/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:45:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/01 22:06:49 by alex             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map, t_player *player, t_sprites *sprites)
{
	static int	frame = 0;

	player->is_mooving = 1;
	if (map->map[player->y - 1][player->x] != '1' && map->map[player->y - 1][player->x] != 'S')
	{
		player->y--;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->sprite = sprites->up_2;
		if (frame == 2)
			player->sprite = sprites->up_3;
		if (frame == 3)
			frame = 0;
	}
	else
	{
		if (player->sprite == sprites->up_idle)
			player->is_mooving = 0;
		frame = 0;
	}
	if (frame == 0)
		player->sprite = sprites->up_idle;
}

void	move_left(t_map *map, t_player *player, t_sprites *sprites)
{
	static int	frame = 0;

	player->is_mooving = 1;
	if (map->map[player->y][player->x - 1] != '1' && map->map[player->y][player->x - 1] != 'S')
	{
		player->x--;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->sprite = sprites->left_2;
		if (frame == 2)
			player->sprite = sprites->left_3;
		if (frame == 3)
			player->sprite = sprites->left_4;
		if (frame == 4)
			frame = 0;
	}
	else
	{
		if (player->sprite == sprites->left_idle)
			player->is_mooving = 0;
		frame = 0;
	}
	if (frame == 0)
		player->sprite = sprites->left_idle;		
}

void	move_down(t_map *map, t_player *player, t_sprites *sprites)
{
	static int	frame = 0;

	player->is_mooving = 1;
	if (map->map[player->y + 1][player->x] != '1' && map->map[player->y + 1][player->x] != 'S')
	{
		player->y++;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->sprite = sprites->down_2;
		if (frame == 2)
			player->sprite = sprites->down_3;
		if (frame == 3)
			frame = 0;
	}
	else
	{
		if (player->sprite == sprites->down_idle)
			player->is_mooving = 0;
		frame = 0;
	}
	if (frame == 0)
		player->sprite = sprites->down_idle;
}

void	move_right(t_map *map, t_player *player, t_sprites *sprites)
{
	static int	frame = 0;

	player->is_mooving = 1;
	if (map->map[player->y][player->x + 1] != '1' && map->map[player->y][player->x + 1] != 'S')
	{
		player->x++;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->sprite = sprites->right_2;
		if (frame == 2)
			player->sprite = sprites->right_3;
		if (frame == 3)
			player->sprite = sprites->right_4;
		if (frame == 4)
			frame = 0;
	}
	else
	{
		if (player->sprite == sprites->right_idle)
			player->is_mooving = 0;
		frame = 0;
	}
	if (frame == 0)
		player->sprite = sprites->right_idle;		
}
