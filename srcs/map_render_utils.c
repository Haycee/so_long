/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:14:22 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/06 12:34:13 by agirardi         ###   ########lyon.fr   */
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
		if (random >= 200 && random < 220)
			map->map[y][x] = '2';
		else if (random >= 220 && random < 240)
			map->map[y][x] = '3';
		else if (random >= 260 && random < 280)
			map->map[y][x] = '5';
		else if (random >= 280 && random < 310)
			map->map[y][x] = '7';
		else if (random >= 310 && random < 320)
			place_enemy(map, x, y);
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

void	place_enemy(t_map *map, int x, int y)
{
	if(!ft_strchr("1S", map->map[y + 1][x]) && !ft_strchr("1S", map->map[y - 1][x]))
	{
		printf("y + 1 : %c\n", map->map[y + 1][x]);
		printf("y - 1 : %c\n", map->map[y - 1][x]);
		map->map[y][x] = 'X';
	}
}

void	select_sprite(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.grass, data->win.x, data->win.y);
	if (ft_strchr("127CP", data->map.map[data->map.y][data->map.x]))
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
	else if (data->map.map[y][x] == '2')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.grass_2, data->win.x, data->win.y);
	else if (data->map.map[y][x] == '7')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.leaf, data->win.x, data->win.y);
	else if (data->map.map[y][x] == 'C') // else 
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.rupee, data->win.x, data->win.y);
}

void	select_sprite_3(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'X')
		display_enemy(data);
	else if (data->map.map[y][x] == 'S')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.stone, data->win.x, data->win.y);
	else if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.exit, data->win.x, data->win.y);
	else if (data->map.map[y][x] == '8') // else 
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.sword, data->win.x, data->win.y);
}

void	select_sprite_4(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '3')
	{
		if (data->sprites.state == 0)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_3, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_4, data->win.x, data->win.y);
	}
	else if (data->map.map[y][x] == '5')
	{
		if (data->sprites.state == 0)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_5, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.grass_6, data->win.x, data->win.y);
	}
}
