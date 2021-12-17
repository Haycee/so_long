/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:57:34 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/17 18:41:35 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int create_map(t_map *map, char *argv)
{
	int		fd;
	char	*unprocessed_map;
	char	*line;

	fd = open_file(argv);
	if (fd == -1)
		return (0);
	unprocessed_map = ft_calloc(1, 1);
	if (!unprocessed_map)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		unprocessed_map = ft_strjoin(unprocessed_map, line); // ! check if join failed
		free(line);
		map->height++;
	}
	map->map = ft_split(unprocessed_map, '\n');
	map->width = ft_strlen(map->map[0]);
	free(unprocessed_map);
	if (close_file(fd) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;

	ft_memset(&data, 0, sizeof(data));
	if (argc < 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) // ! strnstr
	{
		printf("Error\nInvalid path\n");
		return (0);
	}
	if (!create_map(&data.map, argv[1]))
	{
		printf("Error\nFailed to create map\n");
		exit(0);
	}
	if (!parse_map(data.map))
	{
		printf("Error\nInvalid map\n");
		exit(0);
	}
	create_window(&data.win);
	sprites_ini(&data.sprites, &data.win);
	mlx_hook(data.win.window, 2, 0, get_key, &data);
	render_map(&data.map, &data.win, &data.sprites);
	mlx_loop(data.win.mlx);
}



// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// }
