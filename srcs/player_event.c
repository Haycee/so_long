/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:33:57 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/03 14:55:53 by alex             ###   ########lyon.fr   */
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
	if (data->map.map[data->player.y][data->player.x] == 'X')
		printf("loose\n");
	if (data->map.map[data->player.y][data->player.x] == 'E')
	{
		if (data->player.rupees == data->map.rupee_count)
			printf("win\n");
		else
			printf("loose\n");
	}
}
