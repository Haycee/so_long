/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:12:19 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/17 12:56:16 by agirard
i         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void create_window(t_win *win)
{
	win->height = 800; 
	win->width = 1100; 
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, win->width, win->height, "so_long");
}

void	select_sprite(t_map *map, t_win *win, t_sprites *sprites)
{
	mlx_put_image_to_window(win->mlx, win->window, sprites->grass, win->x, win->y);
	if (map->map[win->y / 100][win->x / 100] == '1')
		mlx_put_image_to_window(win->mlx, win->window, sprites->tree, win->x, win->y);
	if (map->map[win->y / 100][win->x / 100] == 'C')
		mlx_put_image_to_window(win->mlx, win->window, sprites->ham, win->x, win->y);
	if (map->map[win->y / 100][win->x / 100] == 'E')
		mlx_put_image_to_window(win->mlx, win->window, sprites->rock, win->x, win->y);
	if (map->map[win->y / 100][win->x / 100] == 'P')
		mlx_put_image_to_window(win->mlx, win->window, sprites->player, win->x, win->y);
}

void	render_map(t_map *map, t_win *win, t_sprites *sprites)
{
	win->y = 0;
	while (win->y < win->height && win->y / 100 < map->height) 
	{
		win->x = 0;
			while (win->x < win->width && win->y / 100 < map->width)
			{
				select_sprite(map, win, sprites);
				win->x += 100;
			}
		win->y += 100;
	}
}
