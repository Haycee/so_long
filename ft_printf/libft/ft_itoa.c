/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:22:47 by agirardi          #+#    #+#             */
/*   Updated: 2021/11/13 10:01:54 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_digits(int num, int sign)
{
	int	digits;

	digits = 0;
	if (num == 0)
		digits++;
	while (num != 0)
	{
		num /= 10;
		digits++;
	}
	if (sign == -1)
		digits++;
	return (digits);
}

static char	*fill_digits(long int num, int digits, int sign, char *result)
{
	result[digits] = '\0';
	while (digits != 0)
	{
		digits--;
		result[digits] = num % 10 + '0';
		num /= 10;
	}
	if (sign == -1)
		result[digits] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			digits;
	int			sign;
	char		*result;

	num = n;
	sign = 1;
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	digits = find_digits(num, sign);
	result = malloc(digits * sizeof(char) + 1);
	if (num == 0)
		result[0] = '0';
	if (!result)
		return (NULL);
	fill_digits(num, digits, sign, result);
	return (result);
}
