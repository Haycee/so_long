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
	sprites->grass = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass_2.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass_3.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_4 = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass_4.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_5 = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass_5.xpm",
		&sprites->size, &sprites->size);
	sprites->grass_6 = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass_6.xpm",
		&sprites->size, &sprites->size);
	sprites->tree = mlx_xpm_file_to_image(win->mlx, "./sprites/wall/plant.xpm",
		&sprites->size, &sprites->size);
	sprites->collectible = mlx_xpm_file_to_image(win->mlx, "./sprites/collectible.xpm",
		&sprites->size, &sprites->size);
	sprites->stone = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/exit.xpm",
		&sprites->size, &sprites->size);
	sprites->enemy = mlx_xpm_file_to_image(win->mlx, "./sprites/enemy/enemy_1.xpm",
		&sprites->size, &sprites->size);
	sprites->enemy_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/enemy/enemy_2.xpm",
		&sprites->size, &sprites->size);
}

void	sprites_ini_2(t_sprites *sprites, t_win *win)
{
	sprites->up_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/up/up_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->up_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/up/up_2.xpm",
		&sprites->size, &sprites->size);
	sprites->up_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/up/up_3.xpm",
		&sprites->size, &sprites->size);
	sprites->down_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/down/down_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->down_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/down/down_2.xpm",
		&sprites->size, &sprites->size);
	sprites->down_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/down/down_3.xpm",
		&sprites->size, &sprites->size);
	sprites->left_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->left_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_2.xpm",
		&sprites->size, &sprites->size);
	sprites->left_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_3.xpm",
		&sprites->size, &sprites->size);
	sprites->left_4 = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_4.xpm",
		&sprites->size, &sprites->size);
	sprites->right_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->right_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_2.xpm",
		&sprites->size, &sprites->size);
	sprites->right_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_3.xpm",
		&sprites->size, &sprites->size);
	sprites->right_4 = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_4.xpm",
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
