/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:57:34 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/22 20:32:36 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// commentaire dans hook.c

// sanitize etc...

static void	create_map(t_map *map, char *argv)
{
	int		fd;
	char	*unprocessed_map;
	char	*line;

	fd = open_file(argv);
	unprocessed_map = ft_calloc(1, 1);
	if (!unprocessed_map)
		error_handler(TECH);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		unprocessed_map = ft_strjoin(unprocessed_map, line);
		if (!unprocessed_map)
			error_handler(TECH);
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
	int			to_exention;

	to_exention = ft_strlen(argv[1]) - 4;
	ft_memset(&data, 0, sizeof(data));
	if (argc != 2 || ft_strnstr(argv[1] + to_exention, ".ber", 4) == NULL)
		error_handler(PATH);
	create_map(&data.map, argv[1]);
	parse_map(&data.map);
	create_window(&data.win, &data.map);
	customize_map(&data.map);
	initialize_all(&data);
	render_map(&data);
	mlx_loop_hook(data.win.mlx, set_animation_state, &data);
	mlx_hook(data.win.window, 3, 0, key_release, &data);
	mlx_hook(data.win.window, 2, 0, key_press, &data);
	mlx_hook(data.win.window, 17, 0, close_window, &data);
	mlx_loop(data.win.mlx);
}
