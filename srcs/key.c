/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:05:32 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/20 18:21:52 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_key(int key, t_data *data)
{
	if (key == 13)
		move_up(&data->map, &data->player, &data->sprites, &data->win);
	if (key == 0)
		move_left(&data->map, &data->player, &data->sprites, &data->win);
	if (key == 1)
		move_down(&data->map, &data->player, &data->sprites, &data->win);
	if (key == 2)
		move_right(&data->map, &data->player, &data->sprites, &data->win);
	if (check_event(&data->map, &data->player))
	{
		if (data->map.c_num == data->player.collected)
			printf("win");
		else
			printf("loose");
	}	
	camera_player(data);	
	return (0);
}

int back_anim(t_data *data)
{
	static int	counter = 0;
	static int	frame = 0;
	int			x;
	int			y;


	y = data->camera.y;
	x = data->camera.x;
	counter++;
	if (counter == 3000)
	{
		if (frame == 0)
			frame = 1;
		else
			frame = 0;

		data->win.y = 0;
		while (y < (data->win.height / 64) + data->camera.y && data->map.map[y])
		{
			data->win.x = 0;
			x = data->camera.x;
			while (x < (data->win.width / 64) + data->camera.x && data->map.map[y][x])
			{
				if (data->map.map[y][x] == 'X')
				{	
					if (frame == 0)
					{
						mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.grass, x * 64, y * 64);
						mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.enemy, x * 64, y * 64);
					}
					else
					{
						mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.grass, x * 64, y * 64);
						mlx_put_image_to_window(data->win.mlx, data->win.window, data->sprites.enemy_2, x * 64, y * 64);
					}
					data->win.x += 64;
				}
				x++;
			}
			data->win.y += 64;
			y++;
		}
		counter = 0;
	}
	return (0);
}