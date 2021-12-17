/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:20:19 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/17 17:31:08 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sprites_ini(t_sprites *sprites, t_win *win)
{
	sprites->player = mlx_xpm_file_to_image(win->mlx, "./sprites/player.xpm",
		&sprites->size, &sprites->size);
	sprites->grass = mlx_xpm_file_to_image(win->mlx, "./sprites/grass.xpm",
		&sprites->size, &sprites->size);
	sprites->tree = mlx_xpm_file_to_image(win->mlx, "./sprites/tree.xpm",
		&sprites->size, &sprites->size);
	sprites->rock = mlx_xpm_file_to_image(win->mlx, "./sprites/rock.xpm",
		&sprites->size, &sprites->size);
	sprites->ham = mlx_xpm_file_to_image(win->mlx, "./sprites/ham.xpm",
		&sprites->size, &sprites->size);
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

int close_file(int fd)
{
	if (close(fd) == -1)
		return (-1);
	return (1);
}
