/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:28:17 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 02:41:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		substring = malloc(sizeof(char) * (len + 1));
	else
		substring = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
