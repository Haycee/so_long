/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:24:44 by agirardi          #+#    #+#             */
/*   Updated: 2021/11/16 19:24:55 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_counter(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			counter++;
		if (s[i] != c && s[i + 1] == '\0')
			counter++;
		i++;
	}
	return (counter);
}

static int	secondary_array_creator(char **splitted, char const *s, char c)
{
	int	i;
	int	i_tab;
	int	j_tab;

	i = 0;
	i_tab = 0;
	while (s[i] && i_tab < word_counter(s, c))
	{
		j_tab = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i + 1] != '\0')
		{
			j_tab++;
			i++;
		}
		if (s[i] != c && s[i + 1] == '\0')
			j_tab++;
		splitted[i_tab] = ft_calloc(j_tab + 1, sizeof(char));
		if (!splitted[i_tab])
			return (0);
		i_tab++;
		i++;
	}
	return (1);
}

static void	fill_array(char **splitted, char const *s, char c)
{
	int	i;
	int	i_tab;
	int	j_tab;

	i = 0;
	i_tab = 0;
	while (s[i] && i_tab < word_counter(s, c))
	{
		j_tab = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i + 1] != '\0')
			splitted[i_tab][j_tab++] = s[i++];
		if (s[i] != c && s[i + 1] == '\0')
			splitted[i_tab][j_tab++] = s[i];
		splitted[i_tab][j_tab] = '\0';
		i_tab++;
		i++;
	}
}

static void	free_all(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = word_counter(s, c);
	splitted = ft_calloc(word_count + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	if (!secondary_array_creator(splitted, s, c))
	{
		free_all(splitted);
		return (NULL);
	}
	fill_array(splitted, s, c);
	return (splitted);
}
