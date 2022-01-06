/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:45:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/06 13:57:05 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map, t_player *player, t_sprites *sprites)
{
	if (player->orientation != 'u' || player->is_mooving == 0)
		player->frame = 0;
	player->orientation = 'u';
	if (!ft_strchr("1S", map->map[player->y - 1][player->x]))
	{
		player->y--;
		player->steps++;
		player->frame++;
		if (player->frame == 1)
			player->sprite = sprites->up_2;
		else if (player->frame == 2)
			player->sprite = sprites->up_3;
		else if (player->frame == 3)
			player->frame = 0;
	}
	else
	{
		if (player->sprite == sprites->up_idle)
			player->is_mooving = 0;
		player->frame = 0;
	}
	if (player->frame == 0)
		player->sprite = sprites->up_idle;
}

void	move_left(t_map *map, t_player *player, t_sprites *sprites)
{
	if (player->orientation != 'l' || player->is_mooving == 0)
		player->frame = 0;
	player->orientation = 'l';
	if (!ft_strchr("1S", map->map[player->y][player->x - 1]))
	{
		player->x--;
		player->steps++;
		player->frame++;
		if (player->frame == 1)
			player->sprite = sprites->left_2;
		else if (player->frame == 2)
			player->sprite = sprites->left_3;
		else if (player->frame == 3)
			player->sprite = sprites->left_4;
		else if (player->frame == 4)
			player->frame = 0;
	}
	else
	{
		if (player->sprite == sprites->left_idle)
			player->is_mooving = 0;
		player->frame = 0;
	}
	if (player->frame == 0)
		player->sprite = sprites->left_idle;
}

void	move_down(t_map *map, t_player *player, t_sprites *sprites)
{
	if (player->orientation != 'd' || player->is_mooving == 0)
		player->frame = 0;
	player->orientation = 'd';
	if (!ft_strchr("1S", map->map[player->y + 1][player->x]))
	{
		player->y++;
		player->steps++;
		player->frame++;
		if (player->frame == 1)
			player->sprite = sprites->down_2;
		else if (player->frame == 2)
			player->sprite = sprites->down_3;
		else if (player->frame == 3)
			player->frame = 0;
	}
	else
	{
		if (player->sprite == sprites->down_idle)
			player->is_mooving = 0;
		player->frame = 0;
	}
	if (player->frame == 0)
		player->sprite = sprites->down_idle;
}

void	move_right(t_map *map, t_player *player, t_sprites *sprites)
{
	if (player->orientation != 'r' || player->is_mooving == 0)
		player->frame = 0;
	player->orientation = 'r';
	if (!ft_strchr("1S", map->map[player->y][player->x + 1]))
	{
		player->x++;
		player->steps++;
		player->frame++;
		if (player->frame == 1)
			player->sprite = sprites->right_2;
		else if (player->frame == 2)
			player->sprite = sprites->right_3;
		else if (player->frame == 3)
			player->sprite = sprites->right_4;
		else if (player->frame == 4)
			player->frame = 0;
	}
	else
	{
		if (player->sprite == sprites->right_idle)
			player->is_mooving = 0;
		player->frame = 0;
	}
	if (player->frame == 0)
		player->sprite = sprites->right_idle;
}

void	idle_player(t_data *data)
{
	data->player.is_mooving = 0;
	if (data->player.orientation == 'u')
		data->player.sprite = data->sprites.up_idle;
	else if (data->player.orientation == 'l')
		data->player.sprite = data->sprites.left_idle;
	else if (data->player.orientation == 'd')
		data->player.sprite = data->sprites.down_idle;
	else if (data->player.orientation == 'r')
		data->player.sprite = data->sprites.right_idle;
	display_player(data);
}
