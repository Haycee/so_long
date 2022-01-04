/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:14:22 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/04 07:11:38 by alex             ###   ########lyon.fr   */
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

void	select_sprite(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.grass, data->win.x, data->win.y);
	if (ft_strchr("0127CP", data->map.map[data->map.y][data->map.x]))
		select_sprite_2(data, data->map.x, data->map.y);
	else if ((ft_strchr("8SXE", data->map.map[data->map.y][data->map.x])))
		select_sprite_3(data, data->map.x, data->map.y);
	else
		select_sprite_4(data, data->map.x, data->map.y);
}

void	select_sprite_2(t_data *data, int x, int y)
{
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

void	select_sprite_3(t_data *data, int x, int y)
{
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

void	select_sprite_4(t_data *data, int x, int y)
{
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