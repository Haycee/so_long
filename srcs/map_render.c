/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:12:19 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/17 12:56:16 by agirard
i         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void create_window(t_win *win, t_map *map)
{
	win->height = map->height * 64;
	win->width = map->width * 64;
	if (map->height > 10)
		win->height = 64 * 10;
	if (map->width > 20)
		win->width = 64 * 20;

	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, win->width, win->height, "so_long");
}

void	modify_map(t_map *map)
{
	int	random;
	int	y;
	int	x;

	random = 0;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			random = myrandom();
			if (map->map[y][x] == '0')
			{
				if (random > 170 && random < 230)
					map->map[y][x] = '2';
				else if (random > 230 && random < 250)
					map->map[y][x] = '3';
				else if (random > 250 && random < 350)
					map->map[y][x] = '5';
			}
		}
	}
}

void	select_sprite(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.grass, data->win.x, data->win.y);
	if (data->map.map[y][x] == '2')
		mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.grass_2, data->win.x, data->win.y);
	if (data->map.map[y][x] == '3')
		mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.grass_3, data->win.x, data->win.y);
	if (data->map.map[y][x] == '4')
		mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.grass_4, data->win.x, data->win.y);
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.tree, data->win.x, data->win.y);
	if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.collectible, data->win.x, data->win.y);
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.stone, data->win.x, data->win.y);
	if (x == data->player.x && y == data->player.y)
	{
		if (!data->player.state)
			mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.down_idle, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window, data->player.state, data->win.x, data->win.y);
	}
}

void	camera_player(t_data *data)
{
	int y = data->player.y - ((data->win.height / 64) / 2); 
	int x = data->player.x - ((data->win.width / 64) / 2);

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

	data->win.y = 0;
	while (y < (data->win.height / 64) + data->camera.y && data->map.map[y])
	{
		data->win.x = 0;
		x = data->camera.x;
		while (x < (data->win.width / 64) + data->camera.x && data->map.map[y][x])
		{
			// printf("%c", data->map.map[y][x]);
			select_sprite(data, x, y);
			data->win.x += 64;
			x++;
		}
		// printf("\n");
		data->win.y += 64;
		y++;
	}
	// printf("\n");
}

// void	render_map(t_data *data)
// {
// 	data->win.y = 0;
// 	while (data->win.y < data->win.height && data->win.y / 64 < data->map.height) 
// 	{
// 		data->win.x = 0;
// 			while (data->win.x < data->win.width && data->win.y / 64 < data->map.width)
// 			{
// 				select_sprite(&data->map, &data->win, &data->sprites, &data->player);
// 				data->win.x += 64;
// 			}
// 		data->win.y += 64;
// 	}
// }

