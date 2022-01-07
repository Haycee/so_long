/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:05:30 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/07 13:24:17 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sprites_ini(t_sprites *sprites, t_win *win)
{
	sprites->rupee = mlx_xpm_file_to_image(win->mlx,
			"./sprites/rupee.xpm", &sprites->size, &sprites->size);
	sprites->down_idle = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/down/down.xpm", &sprites->size, &sprites->size);
	sprites->down_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/down/down_2.xpm", &sprites->size, &sprites->size);
	sprites->down_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/down/down_3.xpm", &sprites->size, &sprites->size);
	sprites->exit = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/exit.xpm", &sprites->size, &sprites->size);
	sprites->fall = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/fall/fall.xpm", &sprites->size, &sprites->size);
	sprites->fall_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/fall/fall_2.xpm", &sprites->size, &sprites->size);
	sprites->fall_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/fall/fall_3.xpm", &sprites->size, &sprites->size);
	sprites->fall_4 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/fall/fall_4.xpm", &sprites->size, &sprites->size);
	sprites->fall_5 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/fall/fall_5.xpm", &sprites->size, &sprites->size);
	sprites->enemy_1 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/enemy/enemy_1.xpm", &sprites->size, &sprites->size);
	sprites->enemy_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/enemy/enemy_2.xpm", &sprites->size, &sprites->size);
}

void	sprites_ini_2(t_sprites *sprites, t_win *win)
{
	sprites->fall_6 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/fall/fall_6.xpm", &sprites->size, &sprites->size);
	sprites->grass = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/grass.xpm", &sprites->size, &sprites->size);
	sprites->grass_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/grass_2.xpm", &sprites->size, &sprites->size);
	sprites->grass_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/grass_3.xpm", &sprites->size, &sprites->size);
	sprites->grass_4 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/grass_4.xpm", &sprites->size, &sprites->size);
	sprites->grass_5 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/grass_5.xpm", &sprites->size, &sprites->size);
	sprites->grass_6 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/grass_6.xpm", &sprites->size, &sprites->size);
	sprites->leaf = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/leaf.xpm", &sprites->size, &sprites->size);
	sprites->left_idle = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/left/left.xpm", &sprites->size, &sprites->size);
	sprites->left_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/left/left_2.xpm", &sprites->size, &sprites->size);
	sprites->left_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/left/left_3.xpm", &sprites->size, &sprites->size);
	sprites->left_4 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/left/left_4.xpm", &sprites->size, &sprites->size);
}

void	sprites_ini_3(t_sprites *sprites, t_win *win)
{
	sprites->plant = mlx_xpm_file_to_image(win->mlx,
			"./sprites/wall/plant.xpm", &sprites->size, &sprites->size);
	sprites->right_idle = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/right/right.xpm", &sprites->size, &sprites->size);
	sprites->right_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/right/right_2.xpm", &sprites->size, &sprites->size);
	sprites->right_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/right/right_3.xpm", &sprites->size, &sprites->size);
	sprites->right_4 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/right/right_4.xpm", &sprites->size, &sprites->size);
	sprites->shoe = mlx_xpm_file_to_image(win->mlx,
			"./sprites/hud/shoe.xpm", &sprites->size, &sprites->size);
	sprites->stone = mlx_xpm_file_to_image(win->mlx,
			"./sprites/wall/stone.xpm", &sprites->size, &sprites->size);
	sprites->sword = mlx_xpm_file_to_image(win->mlx,
			"./sprites/floor/sword.xpm", &sprites->size, &sprites->size);
	sprites->up_idle = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/up/up.xpm", &sprites->size, &sprites->size);
	sprites->up_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/up/up_2.xpm", &sprites->size, &sprites->size);
	sprites->up_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/link/up/up_3.xpm", &sprites->size, &sprites->size);
	sprites->purse = mlx_xpm_file_to_image(win->mlx,
			"./sprites/hud/purse.xpm", &sprites->size, &sprites->size);
}

void	sprites_ini_4(t_sprites *sprites, t_win *win)
{
	sprites->win = mlx_xpm_file_to_image(win->mlx,
			"./sprites/win_500_98.xpm", &sprites->size, &sprites->size);
	sprites->loose = mlx_xpm_file_to_image(win->mlx,
			"./sprites/loose_500_75.xpm", &sprites->size, &sprites->size);
}
