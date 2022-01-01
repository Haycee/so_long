/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:05:32 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/01 22:04:31 by alex             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, t_data *data)
{
	if (key == 13)
		move_up(&data->map, &data->player, &data->sprites);
	if (key == 0)
		move_left(&data->map, &data->player, &data->sprites);
	if (key == 1)
		move_down(&data->map, &data->player, &data->sprites);
	if (key == 2)
		move_right(&data->map, &data->player, &data->sprites);
	if (key == 53)
	{
		mlx_destroy_window(data->win.mlx, data->win.window);
		exit(1); 
	}
	if (data->player.is_mooving)
		render_map(data);	
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 13)
		data->player.sprite = data->sprites.up_idle;
	if (key == 0)
		data->player.sprite = data->sprites.left_idle;
	if (key == 1)
		data->player.sprite = data->sprites.down_idle;
	if (key == 2)
		data->player.sprite = data->sprites.right_idle;
		
	// data->player.idle = 1;
	render_map(data);	
	return (0);
}

int set_animation_state(t_data *data)
{
	static int	counter = 0;
	int			x;
	int			y;

	y = data->camera.y;
	x = data->camera.x;
	counter++;
	if (counter == 5000)
	{
		if (data->sprites.state == 0)
			data->sprites.state = 1;
		else
			data->sprites.state = 0;
		render_map(data);
		counter = 0;
	}
	return (0);
}
		
