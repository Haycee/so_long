/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:21:56 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 02:41:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	int		total;

	total = nmemb * size;
	result = malloc(total);
	if (!result)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
