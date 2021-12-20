/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:25:21 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/20 14:52:15 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse_map(t_map *map)
{
	if (!is_rectangular(map) || !check_chars(map) || !check_borders(map))
		return 0;
	return (1);
}

int	is_rectangular(t_map *map)
{
	int	y;

	y = -1;
	while (map->map[++y])
		if ((int)ft_strlen(map->map[y]) != map->width)
			return (0);
	return (1);
}

int	check_chars(t_map *map)
{
	int		y;
	int		x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (!ft_strchr("01CEPX", map->map[y][x]))
				return (0);
			if (map->map[y][x] == 'C')
				map->c_num++;
			if (map->map[y][x] == 'E')
				map->e_num++;
			if (map->map[y][x] == 'P')
				map->p_num++;
		}
	}
	if (map->c_num < 1 || map->e_num < 1 || map->p_num < 1)
		return (0);
	return (1);
}

int	check_borders(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		if (y == 0 || y == map->height)
		{
			x = -1;
			while (map->map[y][++x])
			{
				if (map->map[y][x] != 49)
					return (0); 
			}
		}
		if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
			return (0);
	}
	return (1);
}
