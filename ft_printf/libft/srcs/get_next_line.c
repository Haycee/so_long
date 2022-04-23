/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:21:32 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 02:41:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	static char	buff[100 + 1] = {};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = get_line(fd, line, buff);
	if (line && ft_strlen(line))
		return (line);
	free(line);
	return (NULL);
}

char	*get_line(int fd, char *line, char *buff)
{
	int		read_ret;
	char	*buff_rest;

	read_ret = 1;
	while (read_ret > 0)
	{
		line = ft_get_next_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_check_nl(buff) != -1)
		{
			buff_rest = &buff[ft_check_nl(buff) + 1];
			while (*buff_rest)
				*buff++ = *buff_rest++;
			*buff = '\0';
			return (line);
		}
		read_ret = read(fd, buff, 100);
		if (read_ret == -1)
			free(line);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
	}
	return (line);
}

char	*ft_get_next_strjoin(char *s1, char *s2)
{
	char	*str;
	int		buff_size;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (ft_check_nl(s2) != -1)
		buff_size = ft_check_nl(s2) + 1;
	else
		buff_size = ft_strlen(s2);
	str = malloc(sizeof(char) * (ft_strlen(s1) + buff_size + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	while (s2[j])
	{
		str[i++] = s2[j++];
		if (s2[j - 1] == '\n')
			break ;
	}
	str[i] = '\0';
	return (str);
}

int	ft_check_nl(char *buff)
{
	int	i;

	if (!buff)
		return (-1);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
