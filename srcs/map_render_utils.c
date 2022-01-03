/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:14:22 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/03 09:33:23 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_char(t_map *map, int x, int y)
{
	static int	sword_counter = 0;
	int			random;

	random = randomize();
	if (map->map[y][x] == '0')
	{
		if (random > 200 && random < 230)
			map->map[y][x] = '2';
		else if (random > 230 && random < 250)
			map->map[y][x] = '3';
		else if (random > 250 && random < 300)
			map->map[y][x] = '5';
		else if (random > 300 && random < 340)
			map->map[y][x] = '7';
		else if (random >= 200 && sword_counter < 1)
		{
			sword_counter++;
			map->map[y][x] = '8';
		}
	}
	if (map->map[y][x] == '1' && x != map->width - 1 && y != map->height - 1)
		if (random > 200)
			map->map[y][x] = 'S';
}

void	select_sprite(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.grass, data->win.x, data->win.y);
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.plant, data->win.x, data->win.y);
	if (data->map.map[y][x] == '2')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.grass_2, data->win.x, data->win.y);
	if (data->map.map[y][x] == '7')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.leaf, data->win.x, data->win.y);
	if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.rupee, data->win.x, data->win.y);
}

void	select_sprite_2(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.grass, data->win.x, data->win.y);
	if (data->map.map[y][x] == '8')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.sword, data->win.x, data->win.y);
	if (data->map.map[y][x] == 'S')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.stone, data->win.x, data->win.y);
	if (data->map.map[y][x] == 'X')
	{
		if (data->sprites.state == 1)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.enemy, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.enemy_2, data->win.x, data->win.y);
	}
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.exit, data->win.x, data->win.y);
}

void	select_sprite_3(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.grass, data->win.x, data->win.y);
	if (data->map.map[y][x] == '3' || data->map.map[y][x] == '4')
	{
		if (data->sprites.state == 0)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_3, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_4, data->win.x, data->win.y);
	}
	if (data->map.map[y][x] == '5' || data->map.map[y][x] == '6')
	{
		if (data->sprites.state == 0)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_5, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_6, data->win.x, data->win.y);
	}
}

void	display_player(t_data *data, int x, int y)
{	
	if (x == data->player.x && y == data->player.y)
	{
		if (!data->player.steps)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.down_idle, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->player.sprite, data->win.x, data->win.y);
	}
}
