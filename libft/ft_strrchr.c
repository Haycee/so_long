/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:27:27 by agirardi          #+#    #+#             */
/*   Updated: 2021/11/12 17:37:01 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_size;

	s_size = ft_strlen(s);
	while (s_size >= 0)
	{
		if (s[s_size] == (char)c)
			return ((char *)s + s_size);
		s_size--;
	}
	return (NULL);
}
