/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:14:22 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/08 19:55:08 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_char(t_map *map, int x, int y)
{
	static int	sword_counter = 0;
	int			random;

	random = randomize();
	if (map->map[y][x] == '0')
	{
		if (random >= 200 && random < 220)
			map->map[y][x] = '2';
		else if (random >= 220 && random < 240)
			map->map[y][x] = '3';
		else if (random >= 260 && random < 280)
			map->map[y][x] = '5';
		else if (random >= 280 && random < 310)
			map->map[y][x] = '7';
		else if (random >= 310 && random < 315)
			map->map[y][x] = 'X';
		else if (random >= 200 && sword_counter < 1)
		{
			sword_counter++;
			map->map[y][x] = '8';
		}
	}
	if (map->map[y][x] == '1' && x != map->width - 1 && y != map->height - 1)
		if (random > 200)
			map->map[y][x] = 'S';
}

char	*get_rupee_sentence(t_data *data)
{
	char	*rupee_count;
	char	*buffer;
	char	*rupee_sentence;

	rupee_count = ft_itoa(data->map.rupee_count);
	buffer = ft_strjoin(ft_itoa(data->player.rupees), "/");
	rupee_sentence = ft_strjoin(buffer, rupee_count);
	free(rupee_count);
	if (rupee_sentence == NULL)
		error_handler(TECH);
	return (rupee_sentence);
}
