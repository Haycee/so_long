/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:07:37 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 02:31:22 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_numbers(unsigned long long nb, unsigned long long base_size, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		print_numbers(nb *(-1), base_size, base);
	}
	if (nb >= 0 && nb < base_size)
	{
		write(1, &base[nb], 1);
	}
	if (nb > base_size - 1)
	{
		print_numbers((nb / base_size), base_size, base);
		print_numbers((nb % base_size), base_size, base);
	}
}

void	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long		base_size;

	base_size = ft_strlen(base);
	print_numbers(nbr, base_size, base);
}

int	divider_signed(long long n, long long div)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / div;
		counter++;
	}
	return (counter);
}

int	check_char(char c)
{
	if (c != '%')
		return (0);
	else
		return (1);
}

void	ft_printstr(char *str)
{
	if (str == NULL)
		ft_putstr_fd("(null)", 1);
	else
		ft_putstr_fd(str, 1);
}
