/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:33:57 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/07 13:19:27 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	event_listener(t_data *data)
{
	if (data->map.map[data->player.y][data->player.x] == 'C')
	{
		data->map.map[data->player.y][data->player.x] = '0';
		data->player.rupees++;
	}
	if (data->map.map[data->player.y][data->player.x] == 'E')
		data->player.orientation = 'f';
}

void	fall(t_data *data)
{
	if (data->player.frame_fall == 0)
		data->player.sprite = data->sprites.fall;
	if (data->player.frame_fall == 1)
		data->player.sprite = data->sprites.fall_2;
	if (data->player.frame_fall == 2)
		data->player.sprite = data->sprites.fall_3;
	if (data->player.frame_fall == 3)
		data->player.sprite = data->sprites.fall_4;
	if (data->player.frame_fall == 4)
		data->player.sprite = data->sprites.fall_5;
	if (data->player.frame_fall == 5)
		data->player.sprite = data->sprites.fall_6;
	if (data->player.frame_fall == 6)
	{
		data->map.end = 1;
		end_it(data);
	}
}

void	end_it(t_data *data)
{
	int	win_y;
	int	win_x;
	int	loose_y;
	int	loose_x;

	win_y = (data->win.height / 2) - 50;
	win_x = (data->win.width / 2) - 250;
	loose_y = (data->win.height / 2) - 37;
	loose_x = (data->win.width / 2) - 250;
	mlx_clear_window(data->win.mlx, data->win.window);
	if (data->player.rupees == data->map.rupee_count)
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.win, win_x, win_y);
	else
		mlx_put_image_to_window(data->win.mlx, data->win.window,
			data->sprites.loose, loose_x, loose_y);
}
