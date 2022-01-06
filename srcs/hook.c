/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:05:32 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/06 15:13:36 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, t_data *data)
{
	if (data->map.end == 1)
		close_window(data);
	if (data->player.orientation != 'f')
	{
		data->player.is_mooving = 1;
		if (key == 13)
			move_up(&data->map, &data->player, &data->sprites);
		if (key == 0)
			move_left(&data->map, &data->player, &data->sprites);
		if (key == 1)
			move_down(&data->map, &data->player, &data->sprites);
		if (key == 2)
			move_right(&data->map, &data->player, &data->sprites);
		if (key == 53)
			close_window(data);
	}
	if (data->player.is_mooving)
	{
		event_listener(data);
		render_map(data);
	}
	return (0);
}

int	set_animation_state(t_data *data)
{
	static int	counter_anim = 0;

	counter_anim++;
	if (counter_anim == 5000 && data->player.frame_fall < 7)
	{
		if (data->sprites.state == 0)
			data->sprites.state = 1;
		else
			data->sprites.state = 0;
		if (data->player.orientation == 'f')
		{
			fall(data);
			data->player.frame_fall++;
		}
		counter_anim = 0;
		if (data->player.frame_fall < 7)
			render_map(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->win.mlx, data->win.window);
	exit(1);
}

int	key_release(int key, t_data *data)
{
	data->player.frame = 0;
	if (key == 13)
		data->player.sprite = data->sprites.up_idle;
	if (key == 0)
		data->player.sprite = data->sprites.left_idle;
	if (key == 1)
		data->player.sprite = data->sprites.down_idle;
	if (key == 2)
		data->player.sprite = data->sprites.right_idle;
	display_player(data);
	return (0);
}
