/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:29:48 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 02:30:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_list	copy;
	int		len;

	len = 0;
	va_start(args, str);
	va_copy(copy, args);
	while (*str)
	{
		if (!check_char(*str))
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		else
		{
			function_caller(*(str + 1), args);
			len += arg_len(*(str + 1), copy);
			str++;
		}
		str++;
	}
	va_end(args);
	return (len);
}

void	function_caller(char type, va_list args)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (type == 's')
		ft_printstr(va_arg(args, char *));
	else if (type == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(va_arg(args, unsigned long long), "0123456789abcdef");
	}
	else if (type == 'i' || type == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
	else if (type == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (type == '%')
		ft_putchar_fd('%', 1);
}

int	arg_len(char c, va_list copy)
{
	int		len;
	char	*str;

	len = 0;
	if (c == 'c')
	{
		va_arg(copy, int);
		return (1);
	}
	if (c == '%')
		return (1);
	if (c == 's')
	{
		str = va_arg(copy, char *);
		if (str == NULL)
			return (6);
		return (ft_strlen(str));
	}
	if (c == 'i' || c == 'd')
		len = divider_signed(va_arg(copy, int), 10);
	if (c == 'x' || c == 'X' || c == 'u')
		len = divider_unsigned(c, va_arg(copy, unsigned int));
	if (c == 'p')
		len = divider_unsigned(c, va_arg(copy, unsigned long long)) + 2;
	return (len);
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_put_unsigned_nbr_fd(nbr / 10, fd);
	}
	ft_putchar_fd(nbr % 10 + '0', fd);
}

int	divider_unsigned(char c, unsigned long long n)
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
		if (c == 'u')
			n = n / 10;
		else
			n = n / 16;
		counter++;
	}
	return (counter);
}
