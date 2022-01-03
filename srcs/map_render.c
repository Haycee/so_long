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

void	create_window(t_win *win, t_map *map)
{
	win->height = map->height * 64;
	win->width = map->width * 64;
	if (map->height > 10)
		win->height = 64 * 15;
	if (map->width > 20)
		win->width = 64 * 25;
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, win->width, win->height, "so_long");
}

void	customize_map(t_map *map)
{
	map->y = 0;
	while (map->map[++map->y])
	{
		map->x = 0;
		while (map->map[map->y][++map->x])
		{
			change_char(map, map->x, map->y);
		}
	}
}

void	render_map(t_data *data)
{
	camera_ini(data);
	data->map.y = data->camera.y;
	data->map.x = data->camera.x;
	data->win.y = 0;
	while (data->map.y < (data->win.height / 64) + data->camera.y
		&& data->map.map[data->map.y])
	{
		data->win.x = 0;
		data->map.x = data->camera.x;
		while (data->map.x < (data->win.width / 64) + data->camera.x
			&& data->map.map[data->map.y][data->map.x])
		{
			if (ft_strchr("0127CP", data->map.map[data->map.y][data->map.x]))
				select_sprite(data, data->map.x, data->map.y);
			if ((ft_strchr("8SXE", data->map.map[data->map.y][data->map.x])))
				select_sprite_2(data, data->map.x, data->map.y);
			if ((ft_strchr("3456", data->map.map[data->map.y][data->map.x])))
				select_sprite_3(data, data->map.x, data->map.y);
			display_player(data, data->map.x, data->map.y);
			data->win.x += 64;
			data->map.x++;
		}
		data->win.y += 64;
		data->map.y++;
	}
}
