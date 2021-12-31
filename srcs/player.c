/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:45:18 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/20 14:18:53 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	static int	frame = 0;

	if (map->map[player->y - 1][player->x] != '1')
	{
		player->y--;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->state = sprites->up_2;
		if (frame == 2)
			player->state = sprites->up_3;
		if (frame == 3)
			frame = 0;
	}
	else
		frame = 0;
	if (frame == 0)
		player->state = sprites->up_idle;		
}

void	move_left(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	static int	frame = 0;

	if (map->map[player->y][player->x - 1] != '1')
	{
		player->x--;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->state = sprites->left_2;
		if (frame == 2)
			player->state = sprites->left_3;
		if (frame == 3)
			player->state = sprites->left_4;
		if (frame == 4)
			frame = 0;
	}
	else
		frame = 0;
	if (frame == 0)
		player->state = sprites->left_idle;		

}

void	move_down(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	static int	frame = 0;

	if (map->map[player->y + 1][player->x] != '1')
	{
		player->y++;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->state = sprites->down_2;
		if (frame == 2)
			player->state = sprites->down_3;
		if (frame == 3)
			frame = 0;
	}
	else
		frame = 0;
	if (frame == 0)
		player->state = sprites->down_idle;		
}

void	move_right(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	static int	frame = 0;

	if (map->map[player->y][player->x + 1] != '1')
	{
		player->x++;
		player->steps++;
		frame++;
		if (frame == 1)	
			player->state = sprites->right_2;
		if (frame == 2)
			player->state = sprites->right_3;
		if (frame == 3)
			player->state = sprites->right_4;
		if (frame == 4)
			frame = 0;
	}
	else
		frame = 0;
	if (frame == 0)
		player->state = sprites->right_idle;		
		
}
