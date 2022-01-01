// HEADER //

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
	sprites->rupee = mlx_xpm_file_to_image(win->mlx, "./sprites/rupee.xpm",
		&sprites->size, &sprites->size);
	sprites->down_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/down/down_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->down_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/down/down_2.xpm",
		&sprites->size, &sprites->size);
	sprites->down_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/down/down_3.xpm",
		&sprites->size, &sprites->size);
	sprites->enemy = mlx_xpm_file_to_image(win->mlx, "./sprites/enemy/enemy_1.xpm",
		&sprites->size, &sprites->size);
    sprites->enemy_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/enemy/enemy_2.xpm",
		&sprites->size, &sprites->size);
	sprites->exit = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/exit.xpm",
		&sprites->size, &sprites->size);
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
}

void	sprites_ini_2(t_sprites *sprites, t_win *win)
{
	sprites->grass_6 = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/grass_6.xpm",
		&sprites->size, &sprites->size);	
	sprites->leaf = mlx_xpm_file_to_image(win->mlx, "./sprites/floor/leaf.xpm",
		&sprites->size, &sprites->size);
	sprites->left_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->left_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_2.xpm",
		&sprites->size, &sprites->size);
	sprites->left_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_3.xpm",
		&sprites->size, &sprites->size);
	sprites->left_4 = mlx_xpm_file_to_image(win->mlx, "./sprites/left/left_4.xpm",
		&sprites->size, &sprites->size);
	sprites->plant = mlx_xpm_file_to_image(win->mlx, "./sprites/wall/plant.xpm",
		&sprites->size, &sprites->size);
	sprites->right_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->right_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_2.xpm",
		&sprites->size, &sprites->size);
	sprites->right_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_3.xpm",
		&sprites->size, &sprites->size);
	sprites->right_4 = mlx_xpm_file_to_image(win->mlx, "./sprites/right/right_4.xpm",
		&sprites->size, &sprites->size);
	sprites->stone = mlx_xpm_file_to_image(win->mlx, "./sprites/wall/stone.xpm",
		&sprites->size, &sprites->size);
}

void	sprites_ini_3(t_sprites *sprites, t_win *win)
{
	sprites->up_idle = mlx_xpm_file_to_image(win->mlx, "./sprites/up/up_idle.xpm",
		&sprites->size, &sprites->size);
	sprites->up_2 = mlx_xpm_file_to_image(win->mlx, "./sprites/up/up_2.xpm",
		&sprites->size, &sprites->size);
	sprites->up_3 = mlx_xpm_file_to_image(win->mlx, "./sprites/up/up_3.xpm",
		&sprites->size, &sprites->size);
}

void	camera_ini(t_data *data)
{
	int	x;
	int	y;

	y = data->player.y - ((data->win.height / 64) / 2); 
	x = data->player.x - ((data->win.width / 64) / 2);

	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (y + data->win.height / 64 > data->map.height)
		y = data->map.height - (data->win.height / 64);
	if (x + data->win.width / 64 > data->map.width)
		x = data->map.width - (data->win.width / 64);

	data->camera.y = y;
	data->camera.x = x;
}