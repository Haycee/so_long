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
		win->height = 64 * 10;
	if (map->width > 20)
		win->width = 64 * 20;
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

void	display_hud(t_data *data)
{
	char 	*rupee_sentence;
	int		offset_steps;
	int		offset_rupees;

	rupee_sentence = ft_strjoin(ft_strjoin(ft_itoa(data->player.rupees), "/"),
		ft_itoa(data->map.rupee_count));
			
	offset_steps = ft_strlen(ft_itoa(data->player.steps));
	offset_rupees = ft_strlen(rupee_sentence);

	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.shoe, 44, 24);
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.purse, 99, 24);
	mlx_string_put(data->win.mlx, data->win.window, 75 - (offset_steps * 3), 83,
		0xFFFFFFFF, ft_itoa(data->player.steps));
	mlx_string_put(data->win.mlx, data->win.window, 128 - (offset_rupees * 3),
	83, 0xFFFFFFFF, rupee_sentence);
	free(rupee_sentence);
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
			select_sprite(data);
			display_player(data, data->map.x, data->map.y);
			data->win.x += 64;
			data->map.x++;
		}
		data->win.y += 64;
		data->map.y++;
	}
	display_hud(data);
}