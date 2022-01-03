/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:57:34 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/03 23:16:51 by alex             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	create_map(t_map *map, char *argv)
{
	int		fd;
	char	*unprocessed_map;
	char	*line;

	fd = open_file(argv);
	unprocessed_map = ft_calloc(1, 1);
	if (!unprocessed_map)
		error_handler(2);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		unprocessed_map = ft_strjoin(unprocessed_map, line);
		if (!unprocessed_map)
			error_handler(2);
		free(line);
		map->height++;
	}
	map->map = ft_split(unprocessed_map, '\n');
	map->width = ft_strlen(map->map[0]);
	free(unprocessed_map);
	close_file(fd);
}

int	main(int argc, char **argv)
{
	t_data		data;

	ft_memset(&data, 0, sizeof(data));
	if (argc < 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) // ! strnstr
		error_handler(1);
	create_map(&data.map, argv[1]);
	parse_map(&data.map);
	create_window(&data.win, &data.map);
	customize_map(&data.map);
	initialize_all(&data);
	render_map(&data);
	mlx_loop_hook(data.win.mlx, set_animation_state, &data);
	mlx_hook(data.win.window, 2, 0, key_press, &data);
	mlx_hook(data.win.window, 3, 0, key_release, &data);
	mlx_hook(data.win.window, 17, 0, close_window, &data);
	mlx_loop(data.win.mlx);
}

// Afficher win / loose
// X pour ennemis
// Limiter nombre exit ?