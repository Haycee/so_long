/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:20:19 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/05 09:14:26 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd != -1)
		error_handler(2);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		error_handler(2);
}

int	randomize(void)
{
	int		result;
	int		fd;
	char	buffer[5];
	int		i;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		error_handler(2);
	read(fd, buffer, sizeof(char) * 3);
	buffer[4] = '\0';
	i = -1;
	result = 0;
	while (buffer[++i])
		result += buffer[i];
	if (close(fd) == -1)
		error_handler(2);
	if (result < 0)
		result *= -1;
	return (result);
}

void	initialize_all(t_data *data)
{
	sprites_ini(&data->sprites, &data->win);
	sprites_ini_2(&data->sprites, &data->win);
	sprites_ini_3(&data->sprites, &data->win);
	sprites_ini_4(&data->sprites, &data->win);
	player_ini(&data->map, &data->player);
}

void	error_handler(int error_num)
{
	if (error_num == 1)
		printf("Error\nInvalid path\n");
	if (error_num == 2)
		printf("Error\nSomething went wrong while creating the map\n");
	if (error_num == 3)
		printf("Error\nInvalid map\n");
	exit(1);
}
