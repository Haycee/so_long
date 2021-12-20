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
	// print_key(key);
	// printf("steps %d\n", data->player.steps);
	render_map(data);	
	return (0);
}


	// if (key == 53)
	// 	printf("ESC\n");
