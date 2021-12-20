/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:20:19 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/20 17:47:09 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_ini(t_map *map, t_player *player)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while(map->map[++x])
		{
			if (map->map[y][x] == 'P')
			{
				player->y = y;
				player->x = x;
			}
		}
	}
}

void	sprites_ini(t_sprites *sprites, t_win *win)
{
	sprites->player = mlx_xpm_file_to_image(win->mlx, "./sprites/player_3.xpm",
		&sprites->size, &sprites->size);
	sprites->grass = mlx_xpm_file_to_image(win->mlx, "./sprites/grass.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/grass_2.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/grass_3.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_4 = mlx_xpm_file_to_image(win->mlx, "./sprites/grass_4.xpm",
		&sprites->size, &sprites->size);
	sprites->tree = mlx_xpm_file_to_image(win->mlx, "./sprites/plant.xpm",
		&sprites->size, &sprites->size);
	sprites->ham = mlx_xpm_file_to_image(win->mlx, "./sprites/collectible.xpm",
		&sprites->size, &sprites->size);
	sprites->rock = mlx_xpm_file_to_image(win->mlx, "./sprites/exit.xpm",
		&sprites->size, &sprites->size);
	sprites->enemy = mlx_xpm_file_to_image(win->mlx, "./sprites/enemy.xpm",
		&sprites->size, &sprites->size);
}

int	check_event(t_map *map, t_player *player)
{
	if (map->map[player->y][player->x] == 'C')
	{
		map->map[player->y][player->x] = '0';
		player->collected++;
	}
	if (map->map[player->y][player->x] == 'X')
		printf("loose\n");
	if (map->map[player->y][player->x] == 'E')
		return (1);
	return (0);
}

int	open_file(char *argv)
{
	int	fd;
	
	fd = open(argv, O_DIRECTORY);
		if (fd != -1)
			return (-1);
	fd = open(argv, O_RDONLY);
		if (fd < 0)
			return (-1);
	return (fd);
}

int	myrandom(void) // check error
{
	int		result;
	int		fd;
	char	buffer[5];
	int		i;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, buffer, sizeof(char) * 3);
	buffer[4] = '\0';
	i = -1;
	result = 0;
	while (buffer[++i])
		result += buffer[i];
	close(fd);
	if (result < 0)
		result *= -1;
	return (result);
}

int	close_file(int fd) // check error
{
	if (close(fd) == -1)
		return (-1);
	return (1);
}
