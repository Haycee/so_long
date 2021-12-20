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

void create_window(t_win *win)
{
	win->height = 384; // 5 6
	win->width = 2176; // 13 34
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
					map->map[y][x] = '4';
			}
		}
	}
}

void	select_sprite(t_map *map, t_win *win, t_sprites *sprites, t_player *player)
{
	mlx_put_image_to_window(win->mlx, win->window, sprites->grass, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == '2')
		mlx_put_image_to_window(win->mlx, win->window, sprites->grass_2, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == '3')
		mlx_put_image_to_window(win->mlx, win->window, sprites->grass_3, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == '4')
		mlx_put_image_to_window(win->mlx, win->window, sprites->grass_4, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == '1')
		mlx_put_image_to_window(win->mlx, win->window, sprites->tree, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == 'C')
		mlx_put_image_to_window(win->mlx, win->window, sprites->ham, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == 'E')
		mlx_put_image_to_window(win->mlx, win->window, sprites->rock, win->x, win->y);
	if (map->map[win->y / 64][win->x / 64] == 'X')
		mlx_put_image_to_window(win->mlx, win->window, sprites->enemy, win->x, win->y);
	mlx_put_image_to_window(win->mlx, win->window, sprites->player, player->x * 64, player->y * 64);
}

void	render_map(t_data *data)
{
	data->win.y = 0;
	while (data->win.y < data->win.height && data->win.y / 64 < data->map.height) 
	{
		data->win.x = 0;
			while (data->win.x < data->win.width && data->win.y / 64 < data->map.width)
			{
				select_sprite(&data->map, &data->win, &data->sprites, &data->player);
				data->win.x += 64;
			}
		data->win.y += 64;
	}
}




// void	select_sprite(t_map *map, t_win *win, t_sprites *sprites, t_player *player)
// {
// 	mlx_put_image_to_window(win->mlx, win->window, sprites->player, player->x, player->y);
// 	mlx_put_image_to_window(win->mlx, win->window, sprites->grass, win->x, win->y);
// 	if (map->map[win->y / 64][win->x / 64] == '1')
// 		mlx_put_image_to_window(win->mlx, win->window, sprites->tree, win->x, win->y);
// 	if (map->map[win->y / 64][win->x / 64] == 'C')
// 		mlx_put_image_to_window(win->mlx, win->window, sprites->ham, win->x, win->y);
// 	if (map->map[win->y / 64][win->x / 64] == 'E')
// 		mlx_put_image_to_window(win->mlx, win->window, sprites->rock, win->x, win->y);
// }

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
