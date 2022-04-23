/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:35:57 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 02:41:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dst[i] == (unsigned char)c)
			return (&dst[i]);
		i++;
	}
	return (NULL);
}
