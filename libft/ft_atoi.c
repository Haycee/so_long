/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:21:32 by agirardi          #+#    #+#             */
/*   Updated: 2021/11/13 14:34:07 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkflow(long nb, short sign)
{
	if (nb > 2147483648 || nb < -2147483649)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)nb * sign);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (nptr[i] == '+')
		nptr++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (ft_checkflow(result, sign));
}
