/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:46:25 by agirardi          #+#    #+#             */
/*   Updated: 2021/11/12 09:44:59 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_size;

	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && i < len)
		{
			j++;
			if (j == needle_size)
				return ((char *)&haystack[i - j + 1]);
			i++;
		}
		i -= j;
		i++;
	}
	return (NULL);
}
