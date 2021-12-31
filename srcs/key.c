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
	int	is_mooving;

	is_mooving = 0;
	if (key == 13)
		is_mooving = move_up(&data->map, &data->player, &data->sprites, &data->win);
	if (key == 0)
		is_mooving = move_left(&data->map, &data->player, &data->sprites, &data->win);
	if (key == 1)
		is_mooving = move_down(&data->map, &data->player, &data->sprites, &data->win);
	if (key == 2)
		is_mooving = move_right(&data->map, &data->player, &data->sprites, &data->win);
	if (check_event(&data->map, &data->player))
	{
		if (data->map.c_num == data->player.collected)
			printf("win");
		else
			printf("loose");
	}
	printf("is_mooving : %d\n", is_mooving);
	if (is_mooving)
		camera_player(data);	
	return (0);
}

int back_anim(t_data *data)
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
		// printf("state = %i\n", data->sprites.state);
		camera_player(data);
		counter = 0;
	}
	return (0);
}
		
			// juste changer state et rajouter if avec state pour map_render.c
			// appeler fonction render ici;