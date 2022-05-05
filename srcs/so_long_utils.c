/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:20:19 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/05 17:27:48 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd != -1)
		error_handler(FOLDER);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_handler(OPEN_FILE);
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		error_handler(CLOSE_FILE);
}

int	randomize(void)
{
	int		result;
	int		fd;
	char	buffer[5];
	int		i;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		error_handler(TECH);
	read(fd, buffer, sizeof(char) * 3);
	buffer[4] = '\0';
	i = -1;
	result = 0;
	while (buffer[++i])
		result += buffer[i];
	if (close(fd) == -1)
		error_handler(TECH);
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

void	error_handler(int error_type)
{
	if (error_type == PATH)
		ft_printf("Error\nInvalid path\n");
	if (error_type == TECH)
		ft_printf("Error\nSomething went wrong while creating the map\n");
	if (error_type == PARSING)
		ft_printf("Error\nInvalid map\n");
	if (error_type == OPEN_FILE)
		ft_printf("Error\nCould not open the map\n");
	if (error_type == CLOSE_FILE)
		ft_printf("Error\nCould not close the map\n");
	if (error_type == FOLDER)
		ft_printf("Error\nPlease open a .ber file\n");
	exit(1);
}
