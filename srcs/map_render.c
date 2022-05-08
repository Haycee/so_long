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

void	display_player(t_data *data)
{	
	if (data->map.x == data->player.x && data->map.y == data->player.y)
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
	char	*rupee_count;
	char	*step_count;
	int		offset_steps;
	int		offset_rupees;

	step_count = ft_itoa(data->player.steps);
	rupee_count = get_rupee_sentence(data);
	offset_steps = ft_strlen(step_count);
	offset_rupees = ft_strlen(rupee_count);
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.shoe, 74, 64);
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.purse, 119, 64);
	mlx_string_put(data->win.mlx, data->win.window, 105 - (offset_steps * 3),
		123, 0xFFFFFFFF, step_count);
	mlx_string_put(data->win.mlx, data->win.window, 148 - (offset_rupees * 3),
		123, 0xFFFFFFFF, rupee_count);
	free(step_count);
	free(rupee_count);
}

void	render_map(t_data *data)
{
	camera_ini(data);
	mlx_clear_window(data->win.mlx, data->win.window);
	data->map.y = data->camera.y;
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
			display_player(data);
			data->win.x += 64;
			data->map.x++;
		}
		data->win.y += 64;
		data->map.y++;
	}
	display_hud(data);
}
