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

void	customize_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[++y])
	{
		x = 0;
		while (map->map[y][++x])
		{
			change_char(map, x, y);
		}
	}
}

void	render_map(t_data *data)
{
	int	x;
	int y;

	camera_ini(data);
	y = data->camera.y;
	x = data->camera.x;

	data->win.y = 0;
	while (y < (data->win.height / 64) + data->camera.y && data->map.map[y])
	{
		data->win.x = 0;
		x = data->camera.x;
		while (x < (data->win.width / 64) + data->camera.x && data->map.map[y][x])
		{
			if (ft_strchr("1234567C", data->map.map[y][x]))
				select_sprite(data, x, y);
			else
				select_sprite_2(data, x, y);
			display_player(data, x, y);
			data->win.x += 64;
			x++;
		}
		data->win.y += 64;
		y++;
	}
}