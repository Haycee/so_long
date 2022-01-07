/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:22:08 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/07 13:22:40 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_ini(t_map *map, t_player *player)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'P')
			{
				player->y = y;
				player->x = x;
			}
		}
	}
}

void	camera_ini(t_data *data)
{
	int	x;
	int	y;

	y = data->player.y - ((data->win.height / 64) / 2);
	x = data->player.x - ((data->win.width / 64) / 2);
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (y + data->win.height / 64 > data->map.height)
		y = data->map.height - (data->win.height / 64);
	if (x + data->win.width / 64 > data->map.width)
		x = data->map.width - (data->win.width / 64);
	data->camera.y = y;
	data->camera.x = x;
}
