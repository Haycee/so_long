/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:18:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/08 19:18:50 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	select_sprite(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.window,
		data->sprites.grass, data->win.x, data->win.y);
	if (ft_strchr("127CP", data->map.map[data->map.y][data->map.x]))
		select_sprite_2(data, data->map.x, data->map.y);
	else if ((ft_strchr("X8SE", data->map.map[data->map.y][data->map.x])))
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
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.rupee, data->win.x, data->win.y);
}

void	select_sprite_3(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'X')
	{
		if (data->sprites.state == 1)
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.enemy_1, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.window,
				data->sprites.enemy_2, data->win.x, data->win.y);
	}
	if (data->map.map[y][x] == 'S')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.stone, data->win.x, data->win.y);
	else if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.exit, data->win.x, data->win.y);
	else if (data->map.map[y][x] == '8')
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
