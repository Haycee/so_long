/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:31:08 by agirardi          #+#    #+#             */
/*   Updated: 2022/01/07 15:21:31 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
void	print_numbers(unsigned long long nb, unsigned long long base_size, char *base);
void	ft_putnbr_base(unsigned long long nbr, char *base);
int		check_char(char c);
void	function_caller(char c, va_list args);
int		arg_len(char c, va_list copy);
int		divider_signed(long long int n, long long div);
int		divider_unsigned(char c, unsigned long long int n);
void	ft_printstr(char *str);

#endif
