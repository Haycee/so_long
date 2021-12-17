/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:25:21 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/17 17:33:53 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse_map(t_map map)
{
	if (!is_rectangular(map) || !check_chars(map) || !check_borders(map))
		return 0;
	return (1);
}

int	is_rectangular(t_map map)
{
	int	y;

	y = -1;
	printf("%c\n", map.map[0][0]);
	while (map.map[++y])
		if ((int)ft_strlen(map.map[y]) != map.width)
			return (0);
	return (1);
}

int	check_chars(t_map map)
{
	int		y;
	int		x;
	int		check[3];

	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	y = -1;
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			if (!ft_strchr("01CEP", map.map[y][x]))
				return (0);
			if (map.map[y][x] == 'C')
				check[0] = 1;
			if (map.map[y][x] == 'E')
				check[1] = 1;
			if (map.map[y][x] == 'P')
				check[2] = 1;
		}
	}
	if (check[0] != 1 || check[1] != 1 || check[2] != 1)
		return (0);
	return (1);
}

int	check_borders(t_map map)
{
	int	y;
	int	x;

	y = -1;
	while (map.map[++y])
	{
		if (y == 0 || y == map.height)
		{
			x = -1;
			while (map.map[y][++x])
			{
				if (map.map[y][x] != 49)
					return (0); 
			}
		}
		if (map.map[y][0] != '1' || map.map[y][map.width - 1] != '1')
			return (0);
	}
	return (1);
}
