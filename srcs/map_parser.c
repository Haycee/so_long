/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:25:21 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/08 14:06:52 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_map *map)
{
	if (!is_rectangular(map) || !check_chars(map) || !check_borders(map))
		error_handler(PARSING);
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
			if (!ft_strchr("01CEP", map->map[y][x]))
				return (0);
			if (map->map[y][x] == 'C')
				map->rupee_count++;
			if (map->map[y][x] == 'E')
				map->exit_count++;
			if (map->map[y][x] == 'P')
				map->player_count++;
		}
	}
	if (map->rupee_count < 1 || map->exit_count < 1
		|| map->player_count < 1)
		return (0);
	return (1);
}

int	check_borders(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y != map->height)
	{
		if (y == 0 || y == map->height - 1)
		{
			x = -1;
			while (map->map[y][++x])
			{
				if (map->map[y][x] != '1')
					return (0);
			}
		}
		else if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
			return (0);
	}
	return (1);
}
