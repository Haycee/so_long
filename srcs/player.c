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
	if (map->map[player->y - 1][player->x] != '1')
	{
		player->y--;
		player->steps++;
	}
}

void	move_left(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	if (map->map[player->y][player->x - 1] != '1')
	{
		player->x--;
		player->steps++;
	}
}

void	move_down(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	if (map->map[player->y + 1][player->x] != '1')
	{
		player->y++;
		player->steps++;
	}
}

void	move_right(t_map *map, t_player *player, t_sprites *sprites, t_win *win)
{
	(void)win;
	(void)sprites;
	if (map->map[player->y][player->x + 1] != '1')
	{
		player->x++;
		player->steps++;
	}
}
