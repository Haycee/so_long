/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:20:19 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/01 21:27:53 by alex             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	randomize(void) // check error
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
